// ATTENTION: Replace all occurences of "XXX" by the compiler name! 

// XXX.cs                                                        HDO, 2006-08-28
// -----
// Main program for compiler generated from XXX.atg with Coco-2.
//=====================================|========================================

using System;
using System.IO;

using Lex = XXXLex;
using Syn = XXXSyn;

public class XXX {

  private static String NAME = "XXX";
  private static bool interactiveMode;

  private static void Abort(String abortKind, String moduleName,
                            String methName,  String descr) {
    Console.WriteLine();
    Console.WriteLine("*** {0} in class {1} method {2}", 
                      abortKind, moduleName, methName);
    Console.WriteLine("*** {0}", descr);
    Console.WriteLine();
    Console.WriteLine();
    Console.WriteLine(NAME + " aborted");
    Utils.Modules(Utils.ModuleAction.cleanupModule);
    if (interactiveMode) {
      Console.Write("type [CR] to quit");
      string dummy = Console.ReadLine();
    } // if
    Environment.Exit(Utils.EXIT_FAILURE);
  } // Abort

  private static int CompileFile(String srcFileName) {
    FileStream srcFs = null;
    try {
      srcFs = new FileStream(srcFileName, FileMode.Open);
    } catch (Exception) {
      Console.WriteLine("*** file \"{0}\" not found", srcFileName);
      return Utils.EXIT_FAILURE;
    } // try/catch
    try {
      Lex.src = new StreamReader(srcFs);
      Console.WriteLine("parsing ...");
      Syn.Parse();
      Lex.src.Close();
      Lex.src.Dispose();
      Lex.src = null;
      String lstFileName = Path.ChangeExtension(srcFileName, ".lst");
      if (Errors.NumOfErrors() > 0) {
        Console.WriteLine("listing ...");
        FileStream lstFs = null;
        try {
          lstFs = new FileStream(lstFileName, FileMode.Create);
        } catch (Exception) {
          Utils.FatalError(NAME, "CompileFile", "file \"{0}\" not created", lstFileName);
          return Utils.EXIT_FAILURE;
        } // try/catch
        StreamWriter lstWriter = null;
        try {
          lstWriter = new StreamWriter(lstFs);
          StreamReader srcFsReader = null;
          try { // open the source file a second time to generate the error listing
            srcFsReader = new StreamReader(new FileStream(srcFileName, FileMode.Open));
            lstWriter.WriteLine(NAME + " (file: \"{0}\")", srcFileName);
            Errors.GenerateListing(srcFsReader, lstWriter, Errors.ListingShape.longListing);
          } finally {
            srcFsReader.Close();
            srcFsReader.Dispose();
          } // try/finally
          Console.WriteLine("{0} error(s) detected", Errors.NumOfErrors());
        } finally {
          lstWriter.Close();
          lstWriter.Dispose();
        } // try/finally
      } else {
        if (File.Exists(lstFileName))
          File.Delete(lstFileName);
        Console.WriteLine("no errors detected");
      } // else
    } finally {
      if (Lex.src != null) {
        Lex.src.Close();
        Lex.src.Dispose();
        Lex.src = null;
      } // if
      Utils.Modules(Utils.ModuleAction.resetModule);
    } // try/finally to make sure srcFs and srcReader are closed
    return Utils.EXIT_SUCCESS;
  } // CompileFile


  public static void Main(String[] args) {
  //-----------------------------------|----------------------------------------
    int result = 0;

    // --- install modules ---
    Utils.InstallModule("Utils",   new Utils.ModuleMethodDelegate(Utils.UtilsMethod  ));
    Utils.InstallModule("Sets",    new Utils.ModuleMethodDelegate(Sets.SetsMethod    ));
    Utils.InstallModule("Errors",  new Utils.ModuleMethodDelegate(Errors.ErrorsMethod));

    Utils.InstallModule("XXXLex",  new Utils.ModuleMethodDelegate(XXXLex.XXXLexMethod));
    Utils.InstallModule("XXXSem",  new Utils.ModuleMethodDelegate(XXXSem.XXXSemMethod));
    Utils.InstallModule("XXXSyn",  new Utils.ModuleMethodDelegate(XXXSyn.XXXSynMethod));

    // --- initialize modules ---
    Utils.Modules(Utils.ModuleAction.initModule);

    Errors.PushAbortMethod(new Errors.AbortMethod(Abort));

    Console.WriteLine("---------------------------");
    Console.WriteLine(" {0} Compiler {1," + (5 - NAME.Length) +"} Version X  ", NAME, "");
    Console.WriteLine(" Frontend gen. with Coco-2");
    Console.WriteLine("---------------------------");
    Console.WriteLine();

    if (args.Length > 0) { // command line mode
      interactiveMode = false;
      Console.WriteLine();
      int i = 0;
      do {
        Console.WriteLine("source file \"{0}\"", args[i]);
        result = CompileFile(args[i]);
        if (result != Utils.EXIT_SUCCESS)
          Environment.Exit(result);
        Console.WriteLine();
        i++;
      } while (i < args.Length);
    } else { // args.Length == 0, interactive mode
      interactiveMode = true;
      for (;;) {
        String srcFileName;
        Utils.GetInputFileName("source file > ", out srcFileName);
        if (srcFileName.Length > 0) {
          result = CompileFile(srcFileName);
          if (result != Utils.EXIT_SUCCESS)
            Environment.Exit(result);
        } // if
        char answerCh;
        do {
          Console.WriteLine();
          Console.Write("[c]ontinue or [q]uit > ");
          answerCh = Char.ToUpper(Console.ReadKey().KeyChar);
        } while (answerCh != 'C' && answerCh != 'Q');
        if (answerCh == 'Q')
          break;
        else // answerCh == 'C'
          Console.WriteLine();
      } // for
    } // else

    Utils.Modules(Utils.ModuleAction.cleanupModule);
    Environment.Exit(Utils.EXIT_SUCCESS);

  } // Main

} // XXX

// End of XXX.cs
//=====================================|========================================