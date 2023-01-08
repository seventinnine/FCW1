// CalcSem.cs                                              HDO, 2006-08-28
// -------------
// Semantic evaluator for table-driven top-down parsing.
// Generated by Coco-2 (PGT).
//=====================================|========================================

using System;
using System.Text;

using Lex = CalcLex;
using Syn = CalcSyn;

public class CalcSem {


  public const String MODULENAME = "CalcSem";

  public static void CalcSemMethod(Utils.ModuleAction action, out String moduleName) {
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
  } // CalcSemMethod


  // *** start of global SYN and SEM declarations from ATG ***
  

  // *** end of global SYN and SEM declarations from ATG ***

  

  private static void NT_Calc() {
    int e = 0;
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Expr(out e);
          break;
        case 2: // SEM
          Console.WriteLine(e);
          break;
      } // switch
    } // for
  } // NT_Calc

  private static void NT_Expr(out int e) {
    int t = 0; e = 0;
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Term(out e);
          break;
        case 2:
          NT_Term(out t);
          break;
        case 3: // SEM
          e = e + t;
          break;
        case 4:
          NT_Term(out t);
          break;
        case 5: // SEM
          e = e - t;
          break;
      } // switch
    } // for
  } // NT_Expr

  private static void NT_Term(out int t) {
    int f = 0; t = 0;
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          NT_Fact(out t);
          break;
        case 2:
          NT_Fact(out f);
          break;
        case 3: // SEM
          t = t * f;
          break;
        case 4:
          NT_Fact(out f);
          break;
        case 5: // SEM
          t = t / f;
          break;
      } // switch
    } // for
  } // NT_Term

  private static void NT_Fact(out int f) {
    f = 0;
    for (;;) {
      switch (Syn.Interpret()) {
        case 0:
          return;
        case 1:
          Lex.GETnumberAttr(out f);
          break;
        case 2:
          NT_Expr(out f);
          break;
      } // switch
    } // for
  } // NT_Fact


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
          NT_Calc();
          break;
      } // switch
    } // for
  } // StartSem

    
} // CalcSem

// End of CalcSem.cs
//=====================================|========================================