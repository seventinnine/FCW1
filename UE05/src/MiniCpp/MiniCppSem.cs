// MiniCppSem.cs                                              HDO, 2006-08-28
// -------------
// Semantic evaluator for table-driven top-down parsing.
// Generated by Coco-2 (PGT).
//=====================================|========================================

using System;
using System.Text;

using Lex = MiniCppLex;
using Syn = MiniCppSyn;

public class MiniCppSem {


  public const String MODULENAME = "MiniCppSem";

  public static void MiniCppSemMethod(Utils.ModuleAction action, out String moduleName) {
  //-----------------------------------|----------------------------------------
    moduleName = MODULENAME;
    switch (action) {
      case Utils.ModuleAction.getModuleName:
        return;
      case Utils.ModuleAction.initModule:
        break;
      case Utils.ModuleAction.resetModule:
        break;
      case Utils.ModuleAction.cleanupModule:
        return;
    } // switch
  } // MiniCppSemMethod


  // *** start of global SYN and SEM declarations from ATG ***
  
  private static int numStats = 0;
  private static int cyclomaticComplexity = 1;
  private static System.Collections.Generic.SortedSet<string> n1 = new System.Collections.Generic.SortedSet<string>();
  private static System.Collections.Generic.SortedSet<string> n2 = new System.Collections.Generic.SortedSet<string>();
  private static int N1 = 0;
  private static int N2 = 0;
  
  private static void PrintAnalysisResults() {
    System.Console.WriteLine("using .NET Framework " + System.Environment.Version);
  
    System.Console.WriteLine("b)");
    System.Console.WriteLine("  Lines of Code:         " + MiniCppLex.curLine);
    System.Console.WriteLine("  Number of statements:  " + numStats);
    System.Console.WriteLine("  Cyclomatic Complexity: " + cyclomaticComplexity);
  
    string n1AsString = // cannot do "using System.Linq" here :(
      System.Linq.Enumerable.Aggregate(n1, (l, r) => l.ToString() + ", " + r.ToString());
    string n2AsString =
      System.Linq.Enumerable.Aggregate(n2, (l, r) => l.ToString() + ", " + r.ToString());
    int n = n1.Count + n2.Count;
    int N = N1 + N2;
    double V = (double)N * System.Math.Log(n, 2);
    double D = (double)(n1.Count * N2) / (double)(2 * n2.Count);
    double E = D * V;
    System.Console.WriteLine("c)");
    System.Console.WriteLine("  n1: " + n1AsString);
    System.Console.WriteLine("  n2: " + n2AsString);
    System.Console.WriteLine("  N1: " + N1);
    System.Console.WriteLine("  N2: " + N2);
    System.Console.WriteLine();
    System.Console.WriteLine("  vocabulary: " + n);
    System.Console.WriteLine("  length:     " + N);
    System.Console.WriteLine("  volume:     " + V.ToString("N2"));
    System.Console.WriteLine("  difficulty: " + D.ToString("N2"));
    System.Console.WriteLine("  effort:     " + E.ToString("N2"));
  }
  
  private static void AddToN1(string item) {
    n1.Add(item); N1++;
  }
  
  private static void AddToN2(string item) {
    n2.Add(item); N2++;
  }
  
  // if user selects "[c]ontinue", we have to reset all of our collected data
  private static void Reset() {
    numStats = 0;
    cyclomaticComplexity = 1;
    n1.Clear();
    n2.Clear();
    N1 = 0;
    N2 = 0;
  }
  

  // *** end of global SYN and SEM declarations from ATG ***

  

  private static void NT_MiniCpp() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          Reset();
          break;
        case 2:
          NT_ConstDef();
          break;
        case 3:
          NT_MutDef();
          break;
        case 4: // SEM
          PrintAnalysisResults();
          break;
      } // switch
    } // for
  } // NT_MiniCpp

  private static void NT_ConstDef() {
    string idStr1 = ""; string idStrN = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Type();
          break;
        case 2:
          Lex.GETidentAttr(out idStr1);
          break;
        case 3: // SEM
          AddToN2(idStr1);
          break;
        case 4:
          NT_Init();
          break;
        case 5:
          Lex.GETidentAttr(out idStrN);
          break;
        case 6: // SEM
          AddToN2(idStrN);
          break;
        case 7:
          NT_Init();
          break;
      } // switch
    } // for
  } // NT_ConstDef

  private static void NT_Init() {
    int n = 0;
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          Lex.GETnumberAttr(out n);
          break;
        case 2: // SEM
          AddToN2(n.ToString());
          break;
      } // switch
    } // for
  } // NT_Init

  private static void NT_MutDef() {
    string idStr = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Type();
          break;
        case 2:
          Lex.GETidentAttr(out idStr);
          break;
        case 3:
          NT_Init();
          break;
        case 4: // SEM
          AddToN2(idStr);
          break;
        case 5:
          NT_FormParList();
          break;
        case 6: // SEM
          AddToN1("()");
          break;
        case 7:
          NT_Block();
          break;
      } // switch
    } // for
  } // NT_MutDef

  private static void NT_VarDef() {
    string idStr1 = ""; string idStrN = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Type();
          break;
        case 2:
          Lex.GETidentAttr(out idStr1);
          break;
        case 3:
          NT_Init();
          break;
        case 4: // SEM
          AddToN2(idStr1);
          break;
        case 5:
          Lex.GETidentAttr(out idStrN);
          break;
        case 6:
          NT_Init();
          break;
        case 7: // SEM
          AddToN2(idStrN);
          break;
      } // switch
    } // for
  } // NT_VarDef

  private static void NT_FormParList() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_FormParTypeRight();
          break;
        case 2:
          NT_Type();
          break;
        case 3:
          NT_FormParTypeRight();
          break;
        case 4:
          NT_FormParTypeRight();
          break;
        case 5:
          NT_Type();
          break;
        case 6:
          NT_FormParTypeRight();
          break;
      } // switch
    } // for
  } // NT_FormParList

  private static void NT_FormParTypeRight() {
    string idStr = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          Lex.GETidentAttr(out idStr);
          break;
      } // switch
    } // for
  } // NT_FormParTypeRight

  private static void NT_Type() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
      } // switch
    } // for
  } // NT_Type

  private static void NT_Block() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_ConstDef();
          break;
        case 2:
          NT_VarDef();
          break;
        case 3:
          NT_Stat();
          break;
        case 4: // SEM
          AddToN1("{}");
          break;
      } // switch
    } // for
  } // NT_Block

  private static void NT_Stat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_EmptyStat();
          break;
        case 2:
          NT_BlockStat();
          break;
        case 3:
          NT_ExprStat();
          break;
        case 4:
          NT_IfStat();
          break;
        case 5:
          NT_WhileStat();
          break;
        case 6:
          NT_BreakStat();
          break;
        case 7:
          NT_InputStat();
          break;
        case 8:
          NT_OutputStat();
          break;
        case 9:
          NT_DeleteStat();
          break;
        case 10:
          NT_ReturnStat();
          break;
        case 11: // SEM
          numStats++;
          break;
      } // switch
    } // for
  } // NT_Stat

  private static void NT_EmptyStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
      } // switch
    } // for
  } // NT_EmptyStat

  private static void NT_BlockStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Block();
          break;
      } // switch
    } // for
  } // NT_BlockStat

  private static void NT_ExprStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Expr();
          break;
      } // switch
    } // for
  } // NT_ExprStat

  private static void NT_IfStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          cyclomaticComplexity++; AddToN1("if");
          break;
        case 2:
          NT_Expr();
          break;
        case 3:
          NT_Stat();
          break;
        case 4: // SEM
          AddToN1("else");
          break;
        case 5:
          NT_Stat();
          break;
      } // switch
    } // for
  } // NT_IfStat

  private static void NT_WhileStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          cyclomaticComplexity++; AddToN1("while");
          break;
        case 2:
          NT_Expr();
          break;
        case 3:
          NT_Stat();
          break;
      } // switch
    } // for
  } // NT_WhileStat

  private static void NT_BreakStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          AddToN1("break");
          break;
      } // switch
    } // for
  } // NT_BreakStat

  private static void NT_InputStat() {
    string idStr = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          AddToN1("cin");
          break;
        case 2:
          Lex.GETidentAttr(out idStr);
          break;
      } // switch
    } // for
  } // NT_InputStat

  private static void NT_OutputStat() {
    string str = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          AddToN1("cout");
          break;
        case 2:
          NT_Expr();
          break;
        case 3:
          Lex.GETstringAttr(out str);
          break;
        case 4: // SEM
          AddToN2(str);
          break;
        case 5:
          NT_Expr();
          break;
        case 6:
          Lex.GETstringAttr(out str);
          break;
        case 7: // SEM
          AddToN2(str);
          break;
      } // switch
    } // for
  } // NT_OutputStat

  private static void NT_DeleteStat() {
    string idStr = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          Lex.GETidentAttr(out idStr);
          break;
      } // switch
    } // for
  } // NT_DeleteStat

  private static void NT_ReturnStat() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Expr();
          break;
      } // switch
    } // for
  } // NT_ReturnStat

  private static void NT_Expr() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_OrExpr();
          break;
        case 2: // SEM
          AddToN1("=");
          break;
        case 3: // SEM
          AddToN1("+=");
          break;
        case 4: // SEM
          AddToN1("-=");
          break;
        case 5: // SEM
          AddToN1("*=");
          break;
        case 6: // SEM
          AddToN1("/=");
          break;
        case 7: // SEM
          AddToN1("%=");
          break;
        case 8:
          NT_OrExpr();
          break;
      } // switch
    } // for
  } // NT_Expr

  private static void NT_OrExpr() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_AndExpr();
          break;
        case 2: // SEM
          AddToN1("||");
          break;
        case 3:
          NT_AndExpr();
          break;
      } // switch
    } // for
  } // NT_OrExpr

  private static void NT_AndExpr() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_RelExpr();
          break;
        case 2: // SEM
          AddToN1("&&");
          break;
        case 3:
          NT_RelExpr();
          break;
      } // switch
    } // for
  } // NT_AndExpr

  private static void NT_RelExpr() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_SimpleExpr();
          break;
        case 2: // SEM
          AddToN1("==");
          break;
        case 3: // SEM
          AddToN1("!=");
          break;
        case 4: // SEM
          AddToN1("<");
          break;
        case 5: // SEM
          AddToN1("<=");
          break;
        case 6: // SEM
          AddToN1(">");
          break;
        case 7: // SEM
          AddToN1(">=");
          break;
        case 8:
          NT_SimpleExpr();
          break;
      } // switch
    } // for
  } // NT_RelExpr

  private static void NT_SimpleExpr() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          AddToN1("+");
          break;
        case 2: // SEM
          AddToN1("-");
          break;
        case 3:
          NT_Term();
          break;
        case 4: // SEM
          AddToN1("+");
          break;
        case 5: // SEM
          AddToN1("-");
          break;
        case 6:
          NT_Term();
          break;
      } // switch
    } // for
  } // NT_SimpleExpr

  private static void NT_Term() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_NotFact();
          break;
        case 2: // SEM
          AddToN1("*");
          break;
        case 3: // SEM
          AddToN1("/");
          break;
        case 4: // SEM
          AddToN1("%");
          break;
        case 5:
          NT_NotFact();
          break;
      } // switch
    } // for
  } // NT_Term

  private static void NT_NotFact() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1: // SEM
          AddToN1("!");
          break;
        case 2:
          NT_Fact();
          break;
      } // switch
    } // for
  } // NT_NotFact

  private static void NT_Fact() {
    int n = 0; string idStr = "";
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          Lex.GETnumberAttr(out n);
          break;
        case 2: // SEM
          AddToN1(n.ToString());
          break;
        case 3: // SEM
          AddToN1("++");
          break;
        case 4: // SEM
          AddToN1("--");
          break;
        case 5:
          Lex.GETidentAttr(out idStr);
          break;
        case 6:
          NT_Expr();
          break;
        case 7:
          NT_ActParList();
          break;
        case 8: // SEM
          AddToN2(idStr);
          break;
        case 9: // SEM
          AddToN1("++");
          break;
        case 10: // SEM
          AddToN1("--");
          break;
        case 11:
          NT_Type();
          break;
        case 12:
          NT_Expr();
          break;
        case 13:
          NT_Expr();
          break;
      } // switch
    } // for
  } // NT_Fact

  private static void NT_ActParList() {
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Expr();
          break;
        case 2:
          NT_Expr();
          break;
      } // switch
    } // for
  } // NT_ActParList


  public delegate void PragmaMethod();
  public static PragmaMethod[] pragmaMethods = {
      // none
    };


  public static void StartSem() {
  //-----------------------------------|----------------------------------------
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_MiniCpp();
          break;
      } // switch
    } // for
  } // StartSem

    
} // MiniCppSem

// End of MiniCppSem.cs
//=====================================|========================================