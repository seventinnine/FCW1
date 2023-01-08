// ==>ModuleName.cs                                              HDO, 2006-08-28
// -------------
// Table-driven top-down syntax analyzer (G-code interpreter).
// Generated by Coco-2 (PGT).
//=====================================|========================================

// --- call pragma meths. and exec. sem. acts. after syntax errors? ---
#define CONTPRAGMAACTS            // !!!must be defined for SG and PGT!!! 
#undef  CONTSEMACTS               // should not be defined 

using System;
using System.Text;

using Lex = ==>LexName;
using Sem = ==>SemName;

public class ==>ModuleName {
                   
  public static String MODULENAME = "==>ModuleName";

  // --- G-code instructions ---
  public enum Instruction {
    T, TA, TC, TCA, NT, NTA, ANY, ANYA, EPS, EPSA, JMP, RET
  } // Instruction

==>GlobalDeclarations

  // --- other constants ---
  private const int MINERRDIST   =   3;
  private const int MAXSTACKLEN  = 100;
  private const int EOFTOK       =   0;
  private const int FIRSTNONTERM = LASTPRAGMA + 1;

  public class NTData {
    public int          startPC;
    public bool         del;
    public Sets.Set256  firstSet;
    public NTData(int startPC, bool del, Sets.Set256 firstSet) {
      this.startPC  = startPC;
      this.del      = del;
      this.firstSet = firstSet;
    } // NTData
  } // NTData
  
  private class GrammarTable {
    public int[]  header = {
      ==>header
    };
    public byte[] code = {
      ==>code
    };
    public NTData[] nts = {
      ==>nts
    };
    public Sets.Set256[] epsSets = {
      ==>epsSets
    };
    public Sets.Set256[] anySets = {
      ==>anySets
    };
    public String[] names = {
      ==>names
    };
  } // GrammarTable;

  private static GrammarTable gt;

  private static int   pc;             // G-code counter
  private static int[] stk;            // stack of G-code return adresses
  private static int   sp;             // stack pointer
  private static bool  mustRead;       // next Lex.token to read
  private static int   altRoot;        // root of alternative chain
  private static bool  leaveOrEnter;   // leaveCnt > 0 OR enterCnt > 0
  private static int   leaveCnt;       // nr. of sem. proc. to leave
  private static int   enterCnt;       // nr. of sem. proc. to enter
  private static int   errDist;        // current error distance
  private static int[] stkAtErr;       // saved stack at error position
  private static int[] newSP;          // new stack length
  private static int[] newPC;          // pc after recovery


  public static void ==>ModuleNameMethod(Utils.ModuleAction action, out String moduleName) {
  //-----------------------------------|----------------------------------------
    moduleName = MODULENAME;
    switch (action) {
      case Utils.ModuleAction.getModuleName:
        return;
      case Utils.ModuleAction.initModule:
        Errors.InstallStopParsingMethod(StopParsing);
        gt       = new GrammarTable();
        stk      = new int[MAXSTACKLEN];
        stkAtErr = new int[MAXSTACKLEN];
        newSP    = new int[LASTTERM + 1];
        newPC    = new int[LASTTERM + 1];
        break;
      case Utils.ModuleAction.resetModule:
        break;
      case Utils.ModuleAction.cleanupModule:
        gt       = null;
        stk      = null;
        stkAtErr = null;
        newSP    = null;
        newPC    = null;
        break;
    } // switch
  } // ==>ModuleNameMethod

  private static void Push(int pc) {
    if (sp < MAXSTACKLEN)
      stk[sp++] = pc;
    else
      Errors.Restriction(MODULENAME, "Push", "parser stack overflow");
  } // Push

  private static int Pop() {
    if (sp > 0)
      return stk[--sp];
    else {
      Errors.CompilerError(MODULENAME, "Pop", "parser stack underflow");
      return 0;
    } // else
  } // Pop

  private static void GetNextToken() {
    for (;;) {
      Lex.GetToken(); // updates Lex.token
      if (Lex.token <= LASTTERM)
        return;
  #if !CONTPRAGMAACTS
      if (NumOfSynErrors() == 0)
  #endif
        Sem.pragmaMethods[Lex.token - LASTTERM - 1]();
    } // for
  } // GetNextToken

  private static int AdrAt(int pc) {
    return (gt.code[pc - 1] |
           (gt.code[pc    ] << 8));
  } // AdrAt

  private static void AdjustPC(ref int pc) {
    if (pc == 0)
      return;
    for (;;)
      switch ((Instruction)gt.code[pc - 1]) {
        case Instruction.T:
        case Instruction.TA:
        case Instruction.TC:
        case Instruction.TCA:
        case Instruction.NT:
        case Instruction.NTA:
        case Instruction.ANY:
        case Instruction.ANYA:
        case Instruction.EPS:
        case Instruction.EPSA:
          return;
        case Instruction.JMP:
          pc = AdrAt(pc + 1);
          break;
        case Instruction.RET:
          pc = 0;
          return;
        default:
          pc++; // syn. or sem. action
          break;
      } // switch
  } // AdjustPC

  private static void GetSymInstr(int pc, 
                        out int opcode, out int sy, out int nextPC, out int altPC) {
    opcode = gt.code[pc - 1];
    nextPC = 0; // dummy init
    altPC  = 0; // dummy init 
    switch ((Instruction)opcode) {
      case Instruction.T:
      case Instruction.TA:
      case Instruction.TC:
      case Instruction.TCA:
      case Instruction.ANYA:
      case Instruction.EPS:
      case Instruction.EPSA:
        sy = gt.code[pc];
        break;
      case Instruction.NT:
      case Instruction.NTA:
        sy = gt.code[pc] + FIRSTNONTERM;
        break;
      default: // ANY, JMP, RET, SEM, SYN 
        sy = 0;
        break;
    } // switch
    switch ((Instruction)opcode) {
      case Instruction.T:
      case Instruction.EPS:
        nextPC = pc + 2;
        altPC = 0;
        break;
      case Instruction.TC:
      case Instruction.NT:
        nextPC = pc + 3;
        altPC = 0;
        break;
      case Instruction.TA:
      case Instruction.ANYA:
      case Instruction.EPSA:
        nextPC = pc + 4;
        altPC = AdrAt(pc + 2);
        break;
      case Instruction.TCA:
      case Instruction.NTA:
        nextPC = pc + 5;
        altPC = AdrAt(pc + 2);
        break;
      case Instruction.ANY:
        nextPC = pc + 1;
        altPC = 0;
        break;
    } // switch
    AdjustPC(ref nextPC);
    AdjustPC(ref altPC);
  } // GetSymInstr

  private static void Fill(int pc, int sp) {
    int opcode, sy, nextPC, altPC, i;
    AdjustPC(ref pc);
    while (pc > 0) {
      GetSymInstr(pc, out opcode, out sy, out nextPC, out altPC);
      switch ((Instruction)opcode) {
        case Instruction.T:
        case Instruction.TA:
        case Instruction.TC:
        case Instruction.TCA:
          newPC[sy] = pc;
          newSP[sy] = sp;
          break;
        case Instruction.NT:
        case Instruction.NTA:
          for (i = 0; i <= LASTTERM; i++)
            if (Sets.member((ushort)i, gt.nts[sy - FIRSTNONTERM].firstSet)) {
              newPC[i] = pc;
              newSP[i] = sp;
            }
          if (gt.nts[sy - FIRSTNONTERM].del)
            Fill(nextPC, sp);
          break;
        case Instruction.EPS:
        case Instruction.EPSA:
          Fill(nextPC, sp);
          break;
      } // switch
      pc = altPC;
    } // while
  } // Fill

  private static void FillSucc(int pc, int sp) {
    int opcode, sy, nextPC, altPC;
    AdjustPC(ref pc);
    while (pc > 0) {
      GetSymInstr(pc, out opcode, out sy, out nextPC, out altPC);
      if (nextPC > 0)
        Fill(nextPC, sp);
      pc = altPC;
    } // while
  } // FillSucc

  private static void Triple(int altRoot) {
    for (int i = 0; i <= LASTTERM; i++) { // clear triple list
      newPC[i] = 0;
      newSP[i] = 0;
    } // for
    for (int i = 1; i <= sp; i++) {       // successors of stacked nt's
      FillSucc(stk[i - 1], i - 1);
      Fill(stk[i - 1], i - 1);
    } // for
    FillSucc(altRoot, sp);                // successors of alt. chain
    Fill(altRoot, sp);                    // current alt. chain
  } // Triple

  private static void HandleSynErr(ref int pc, ref int altRoot) {
    int     opcode, sy, nextPC, altPC, adjPC, nwSP, eq;
    bool    nameInMsg;
    String  name;
    StringBuilder msg = new StringBuilder();
    leaveOrEnter = false;
    if (errDist >= MINERRDIST) { // --- primary error
      nameInMsg = false;
      adjPC = altRoot;
      AdjustPC(ref adjPC);
      while (adjPC > 0) {
        GetSymInstr(adjPC, out opcode, out sy, out nextPC, out altPC);
        if ( (Instruction)opcode >= Instruction.T  && 
             (Instruction)opcode <= Instruction.NTA  ) {
          if ( gt.names[sy].IndexOf(' ') >= 0 || 
               !Char.IsLetter(gt.names[sy][0]) )
            name = "\"" + gt.names[sy] + "\"";
          else
            name = gt.names[sy];
          if (name.IndexOf('{') > -1) // prevent formatting problems in Errors.SynError
            name = name.Replace("{", "{{");
          if (name.IndexOf('}') > -1) // prevent formatting problems in Errors.SynError
            name = name.Replace("}", "}}");
          if (msg.Length + name.Length + 2 > 80) {
            msg.Append(" ...");
            break;
          } // if
          if (!nameInMsg) {
            nameInMsg = true;
            msg.Append("expected: " + name);
          } else {
            msg.Append(", ");
            msg.Append(name);
          } // else
        } // if
        adjPC = altPC;
      } // while
      if (!nameInMsg)
        msg.Append("syntax error");
      Errors.SynError(Lex.tokenLine, Lex.tokenCol, msg.ToString(), "");
      Triple(altRoot);
      while (newPC[Lex.token] == 0) {
        GetNextToken();      // may result in a call to StopParsing
        if (leaveOrEnter)
          return;
      } // while
      nwSP = newSP[Lex.token];
      leaveCnt = sp - nwSP;
      enterCnt = 0;
      Array.Copy(stk, stkAtErr, stk.Length); // save stack
    } else {                 // --- spurios error
      if (errDist == 0) {    // no token used since last error
        GetNextToken();      // may result in a call to StopParsing
        if (leaveOrEnter)
          return;
      } // if
      while (newPC[Lex.token] == 0) {
        GetNextToken();      // may result in a call to StopParsing
        if (leaveOrEnter) 
          return;
      } // while
      nwSP = newSP[Lex.token];
      eq = 2;                // compare stkAtErr and stk
      while (eq <= sp && eq <= nwSP && stkAtErr[eq - 1] == stk[eq - 1])
        eq++;
      eq--;                  // stacks are equal up to index eq
      leaveCnt = sp - eq;
      if (nwSP < eq) {
        leaveCnt = sp - nwSP;
        enterCnt = 0;
      } else if (nwSP > eq)
        enterCnt = nwSP - eq;
      else // nwSP == eq
        enterCnt = 0;
      Array.Copy(stkAtErr, stk, stk.Length); // restore stack
    } // else
    leaveOrEnter = (leaveCnt + enterCnt) > 0;
    sp = nwSP;
    pc = newPC[Lex.token];
    altRoot = pc;
    errDist = 0;
  } // HandleSynErr

  public static int Interpret() {
  //-----------------------------------|----------------------------------------
    int actionNr, opcode, currPC;
    for (;;) {
      opcode = gt.code[pc - 1];
      if ( !leaveOrEnter && mustRead && 
           (Instruction)opcode <= Instruction.EPSA ) {
        GetNextToken();
        mustRead = false;
        errDist++;
        altRoot = pc;
      } // if
      if (leaveOrEnter) {
        if (leaveCnt > 0) {
          leaveCnt--;
          actionNr = 0;
        } else { // enterCnt > 0
          enterCnt--;
          actionNr = gt.code[stkAtErr[sp - enterCnt - 1] - 2];
        } // else
        leaveOrEnter = (leaveCnt + enterCnt) > 0;
        return actionNr;
      } // if
      pc++;
      switch ((Instruction)opcode) {
        case Instruction.T:
          if (Lex.token == gt.code[pc - 1])
            if (Lex.token != EOFTOK) {
              pc++;
              mustRead = true;
            } else {
              return 0;
            } // else
          else
            HandleSynErr(ref pc, ref altRoot);
          break;
        case Instruction.TA:
          if (Lex.token == gt.code[pc - 1]) {
            pc += 3;
            mustRead = true;
          } else
            pc = AdrAt(pc + 1); // try alternative
          break;
        case Instruction.TC:
          if (Lex.token == gt.code[pc - 1]) {
            pc += 2;
            mustRead = true;
            actionNr = gt.code[pc - 2];
            return actionNr;
          } else
            HandleSynErr(ref pc, ref altRoot);
          break;
        case Instruction.TCA:
          if (Lex.token == gt.code[pc - 1]) {
            pc += 4;
            mustRead = true;
            actionNr = gt.code[pc - 2];
            return actionNr;
          } else
            pc = AdrAt(pc + 1); // try alternative
          break;
        case Instruction.NT:
          currPC = gt.code[pc - 1];
          if ( gt.nts[currPC].del || 
               Sets.member((ushort)Lex.token, gt.nts[currPC].firstSet) ) {
            pc++;
            actionNr = gt.code[pc - 1];
            Push(pc + 1);
            pc = gt.nts[currPC].startPC;
            altRoot = pc;
            return actionNr;
          } else
            HandleSynErr(ref pc, ref altRoot);
          break;
        case Instruction.NTA:
          currPC = gt.code[pc - 1];
          if (Sets.member((ushort)Lex.token, gt.nts[currPC].firstSet)) {
            pc += 3;
            actionNr = gt.code[pc - 1];
            Push(pc + 1);
            pc = gt.nts[currPC].startPC;
            altRoot = pc;
            return actionNr;
          } else
            pc = AdrAt(pc + 1);
          break;
        case Instruction.ANY:
          mustRead = true;
          break;
        case Instruction.ANYA:
          currPC = gt.code[pc - 1];
          if (Sets.member((ushort)Lex.token, gt.anySets[currPC - 1])) {
            pc += 3;
            mustRead = true;
          } else
            pc = AdrAt(pc + 1);
          break;
        case Instruction.EPS:
          currPC = gt.code[pc - 1];
          if (Sets.member((ushort)Lex.token, gt.epsSets[currPC - 1]))
            pc++;
          else
            HandleSynErr(ref pc, ref altRoot);
          break;
        case Instruction.EPSA:
          currPC = gt.code[pc - 1];
          if (Sets.member((ushort)Lex.token, gt.epsSets[currPC - 1]))
            pc += 3;
          else
            pc = AdrAt(pc + 1);
          break;
        case Instruction.JMP:
          pc = AdrAt(pc);
          break;
        case Instruction.RET:
          pc = Pop();
          altRoot = pc;
          return 0;
        default:
          if (opcode <= 128) {
  #if !CONTSEMACTS
          if (Errors.NumOfSynErrors() == 0)
  #endif
            return opcode - 12;
          } else // opcode > 128
            return opcode - 128;
          break;
      } // switch
    } // for
  } // Interpret


  public static bool Parse() {
  //-----------------------------------|----------------------------------------
    Lex.InitLex();
    sp           = 0;
    pc           = ROOTPC;
    altRoot      = pc;
    mustRead     = true;
    errDist      = MINERRDIST + 1;
    leaveOrEnter = false;
    leaveCnt     = 0;
    enterCnt     = 0;
    Sem.StartSem();
    return Errors.NumOfSynErrors() == 0;
  } // Parse


  public static void StopParsing() {
  //-----------------------------------|----------------------------------------
    leaveCnt     = sp + 1;
    enterCnt     = 0;
    leaveOrEnter = true;
  } // StopParsing

} // ==>ModuleName
 
// End of ==>ModuleName.cs
//=====================================|========================================
