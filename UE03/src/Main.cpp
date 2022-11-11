// Main.cpp:                                              HDO, 2006-2021
// --------
// Simple main program for
// *     deterministic finite automata (DFA) and
// * non-deterministic fintie automata (NFA).
//======================================================================

#include <cstdio>          // for getchar only
#include <iostream>
#include <stdexcept>

using namespace std;

#include "SignalHandling.h"
#include "TapeStuff.h"
#include "StateStuff.h"
#include "MbMatrix.h"
#include "DeltaStuff.h"
#include "FA.h"
#include "DFA.h"
#include "NFA.h"
#include "FABuilder.h"
#include "GraphVizUtil.h"
#include "Stopwatch.hpp"


// Activation (1) allows simple builds via command line:
// * for GNU   use:  g++      -std=c++17 Main.cpp
// * for Clang use:  clang++  -std=c++17 Main.cpp
// * for M.S.  use:  cl /EHsc /std:c++17 Main.cpp
#if 1
  #include "SignalHandling.cpp"
  #include "TapeStuff.cpp"
  #include "StateStuff.cpp"
  #include "MbMatrix.cpp"
  #include "DeltaStuff.cpp"
  #include "FA.cpp"
  #include "DFA.cpp"
  #include "NFA.cpp"
  #include "MooreDFA.cpp"
  #include "FABuilder.cpp"
  #include "GraphVizUtil.cpp"
  #include "Timer.cpp"
  #include "SymbolStuff.cpp"
  #include "SequenceStuff.cpp"
  #include "GrammarBasics.cpp"
  #include "GrammarBuilder.cpp"
  #include "Grammar.cpp"
#endif

Grammar* newEpsilonFreeGrammarOf(const Grammar* g) {
    // step 1
    VNt deletable = g->deletableNTs();

    // step 2
    // use symbolpool to get instances by name 
    // (symbols from initial creation are still stored in SymbolPoolData)
    SymbolPool sp{};
    GrammarBuilder gb{ g->root }; // reuse old root for now

    // for each rule
    // c++20 structured binding
    for (const auto& [nt, sequenceSet] : g->rules)
    {
        // iterate over old sequence set
        for (const Sequence* seq : sequenceSet)
        {
            // begone epsilon
            if (seq->isEpsilon()) continue;

            // add copy
            gb.addRule(nt, new Sequence(*seq));

            // evaluate which indices of current sequence are deletable NTs
            std::vector<int> deletableNTindices{};
            for (int i = 0; i < seq->size(); i++) {
                Symbol* currSy = seq->at(i);
                if (currSy->isNT() &&
                    deletable.contains(dynamic_cast<NTSymbol*>(currSy))) {
                    deletableNTindices.push_back(i);
                }
            }

            // add the current sequence with every possible combination
            // of not including NTs in deletableNTindices
            // 2^n(-1) iterations
            for (int i = 0; i < 1 << deletableNTindices.size(); ++i) {
                Sequence* copy = new Sequence(*seq);
                for (int j = deletableNTindices.size() - 1; j >= 0; --j) {
                    // generate all possible combinations 
                    // of indices in deletableNTindices
                    int symbolsRemoved = 0;
                    if (((1 << j) & i) > 0) {
                        copy->removeSymbolAt(deletableNTindices[j - symbolsRemoved]);
                        symbolsRemoved += 1;
                    }
                }
                // don't add empty alternatives
                // also duplicates are ignored
                if (!copy->isEpsilon()) gb.addRule(nt, copy);
                else delete copy;   
            }
        }
    }

    // step 3
    if (deletable.contains(g->root)) {
        // add S' (or rather name of original root node + ')
        NTSymbol* newRoot = sp.ntSymbol(g->root->name + "'");
        gb.addRule(newRoot, { new Sequence({g->root}), new Sequence() /* eps */ });
        gb.setNewRoot(newRoot);
    }

    return gb.buildGrammar();
}

FA *faOf(const Grammar *g) 
{
  bool deleteG = false;
  FABuilder fab{};
  // ensure g is epsilon-free
  if (!g->isEpsilonFree()) {
    deleteG = true;
    g = newEpsilonFreeGrammarOf(g);
  }

  // set final states
  if (deleteG) { // means that g has S' => is end state
    fab.addFinalState(g->root->name);
  }
  fab.setStartState(g->root->name);
  // generic end state "END" for alternatives without NT
  fab.addFinalState("END");

  for (auto [ntSy, alternatives] : g->rules) {
    for (auto alternative : alternatives) {
      // size of alternative can only be 1 or 2 in regular grammar
      if (alternative->size() == 1) { // no ntSy in alternative => edge to end state with symbol before at pos 0
        fab.addTransition(ntSy->name, alternative->at(0)->name[0], "END");
      } else { // ntSy has edge to ntSy in alternative with symbol before at pos 0
        fab.addTransition(ntSy->name, alternative->at(0)->name[0], alternative->at(1)->name);
      }
    }
  }

  // delete generated epsilon-free grammar
  if (deleteG) delete g;

  //auto nfa = fab.buildNFA();
  //auto dfa = nfa->dfaOf();
  //auto res = dfa->minimalOf();
  //delete nfa; delete dfa;
  return fab.buildNFA();
}


/*
FA *faOf(const Grammar *g) 
{
  FABuilder fab{};
  // start state is root of grammar
  fab.setStartState(g->root->name);

  // go over each rule in grammar
  for (auto [ntSy, alternatives] : g->rules) {
    // determine the end states for the TSymbol of the current alternative
    // if we have A -> a | a B, then end state of the alternative 'a' is B
    // but if we have A -> a | a C | a B
    map<char, string> endStateForTS{};
    for (Sequence* alternative : alternatives) {
      if (alternative->size() == 2) {
        endStateForTS[alternative->at(0)->name[0]] = alternative->at(1)->name;
        fab.addFinalState(alternative->at(1)->name);
      }
      else {

      }
    }

    // go over each alternative
    for (Sequence* alternative : alternatives) {
      char ts = alternative->at(0)->name[0];
      
      if (alternative->hasTerminalsOnly() == 1) { // no ntSy in alternative => edge 
                                      // to end state for that tape symbol
                                      // with symbol before at pos 0
        if (endStateForTS[ts] != "") {
          fab.addTransition(ntSy->name, ts, endStateForTS[ts]);
        } else {
          fab.addTransition(ntSy->name, ts, ntSy->name + "'");
          fab.addFinalState(ntSy->name + "'");
        }
      } else { // ntSy has edge to ntSy in alternative with symbol before at pos 0
        fab.addTransition(ntSy->name, ts, alternative->at(1)->name);
      }
    }
  }

  return fab.buildNFA();
}
*/
Grammar* grammarOf(const FA* fa) {

  SymbolPool sp{};
  GrammarBuilder gb{sp.ntSymbol(fa->s1)};

  // iterate over each state
  for (const State& state : fa->S) {
    // iterate over each tape symbol
    for (const TapeSymbol& ts : fa->V) {
      // get all possible transition destinatons from state using tape symbol
      auto destinations = fa->deltaAt(state, ts);
      for (const State& dest : destinations) {
        // add this transition to grammar as alternative

        // takes care of states like E'
        // if dest does not have any outgoing tape symbols
        // => ignore in grammar
        bool hasOutgoing = false;
        for (const TapeSymbol& ts1 : fa->V) {
          if (fa->deltaAt(dest, ts1).size() > 0) {
            hasOutgoing = true;
          }
        }

        if (hasOutgoing) {
          gb.addRule(sp.ntSymbol(state), 
            new Sequence({
              sp.tSymbol(string{ts}), 
              sp.ntSymbol(dest)}
              )
          );
        } else {
          gb.addRule(sp.ntSymbol(state), 
            new Sequence({sp.tSymbol(string{ts})})
          );
        }         

        // if dest is an end state, also add alternative without dest
        if (fa->F.contains(dest)) {
          gb.addRule(sp.ntSymbol(state), 
            new Sequence(sp.tSymbol(string{ts}))
          );
        }
      }
    }
  }

  // if start state is also end state, add epsilon as alternative
  if (fa->F.contains(fa->s1)) {
    gb.addRule(sp.ntSymbol(fa->s1), new Sequence());
  }

  return gb.buildGrammar();
}

void TimeAccept(NFA* abc, void (*func)(NFA* abc)) {
  stopwatch::Stopwatch sw{};
  sw.start();
  func(abc);
  cout << "Elapsed time: " << sw.elapsed<stopwatch::Stopwatch::TimeFormat::MICROSECONDS>() << " micro sec" << endl;
}

int main(int argc, char *argv[]) {

  FABuilder *fab            = nullptr;
  DFA       *dfa            = nullptr;
  NFA       *nfa            = nullptr;
  DFA       *dfaOfNfa       = nullptr;
  DFA       *minDfaOfNfa    = nullptr;
  DFA       *renMinDfaOfNfa = nullptr;

  installSignalHandlers(); // to catch signals, especially SIGSEGV

  cout << "START: Main" << endl;
  cout << endl;

try {

  cout << "1. DFA" << endl;
  cout << "------" << endl;
  cout << endl;

  int buildCase = 1;
  switch (buildCase) {
    case 1: // programmatical init. of builder
      fab = new FABuilder(); // example from FS slides p. 47
      fab->setStartState("B").
           addFinalState("R").
           addTransition("B", 'b', "R").
           addTransition("R", 'b', "R").
           addTransition("R", 'z', "R");
      break;
    case 2: // init. builder from text file
      fab = new FABuilder(string("IdDFA.txt"));
      break;
    case 3: // init. builder from C string literal
      fab = new FABuilder(
        "-> B -> b R  \n\
         () R -> b R | z R");
      break;
    default:
      throw runtime_error("invalid buildCase");
  } // switch

  delete fab;

  #pragma region HUE1
  
  cout << "1.a) faOf" << endl;
  cout << "------" << endl;
  cout << endl;
  
  GrammarBuilder gb{"G(B):           \n\
                    B -> b | b R | b E    \n\
                    R -> b | z | b R | z R \n\
                    E -> e"};

  Grammar* g = gb.buildGrammar();
  FA* faOfG = faOf(g);

  vizualizeFA("faOfG", faOfG);

  cout << "1.b) grammarOf" << endl;
  cout << "------" << endl;
  cout << endl;

  Grammar* gOfFaOfG = grammarOf(faOfG);

  std::cout << *gOfFaOfG;

  delete g;
  delete faOfG;
  delete gOfFaOfG;

  #pragma endregion HUE1

  #pragma region HUE2A

  cout << "2.a) DFA" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("B").
    addFinalState("R").
    addTransition("B", 'b', "R").
    addTransition("R", 'b', "R").
    addTransition("R", 'z', "R");

  dfa = fab->buildDFA();
  vizualizeFA("dfa", dfa);

  cout << "dfa->accepts(\"bzb\") = " << dfa->accepts("bzb") << endl;
  cout << "dfa->accepts(\"z\")   = " << dfa->accepts("z")   << endl;
  cout << endl;

  delete fab;

  #pragma endregion HUE2A

  #pragma region HUE2B

  cout << "2.b) MooreDFA" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("S").
    addFinalState("B").
    addFinalState("Z").
    addTransition("S", 'b', "B").
    addTransition("B", 'b', "B").
    addTransition("B", 'z', "Z").
    addTransition("Z", 'z', "Z").
    addTransition("Z", 'b', "B").
    setSetMooreLambda({
      {"S", ' '},
      {"B", 'c'}, 
      {"Z", 'd'}
    });

  MooreDFA* mooreDfa = fab->buildMooreDFA();

  cout << "mooreDfa->accepts(\"bzzb\") = " << mooreDfa->accepts("bzzb") << endl;
  cout << "mooreDfa->accepts(\"zzb\") = " << mooreDfa->accepts("zzb") << endl;

  vizualizeFA("mooreDfa", mooreDfa);
  
  delete mooreDfa;
  delete fab;

  #pragma endregion HUE2B

  #pragma region HUE3A

  cout << "3.a)" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("S").
    addFinalState("R").
    addTransition("S", 'a', "S").
    addTransition("S", 'b', "S").
    addTransition("S", 'c', "S").
    addTransition("S", 'a', "A").
    addTransition("S", 'b', "B").
    addTransition("S", 'c', "C").
    addTransition("A", 'a', "A").
    addTransition("A", 'b', "A").
    addTransition("A", 'c', "A").
    addTransition("B", 'a', "B").
    addTransition("B", 'b', "B").
    addTransition("B", 'c', "B").
    addTransition("C", 'a', "C").
    addTransition("C", 'b', "C").
    addTransition("C", 'c', "C").
    addTransition("A", 'a', "R").
    addTransition("B", 'b', "R").
    addTransition("C", 'c', "R");

  NFA* abc = fab->buildNFA();
  cout << "abc->accepts1(\"cabcabcabcabcc\") = " << abc->accepts1("cabcabcabcabcc") << endl;
  cout << "abc->accepts2(\"cabcabcabcabcc\") = " << abc->accepts2("cabcabcabcabcc") << endl;
  cout << "abc->accepts3(\"cabcabcabcabcc\") = " << abc->accepts3("cabcabcabcabcc") << endl;

  cout << "abc->accepts1(\"caaaaaaaaaaaaaaad\") = " << abc->accepts1("caaaaaaaaaaaaaaad") << endl;
  cout << "abc->accepts2(\"caaaaaaaaaaaaaaad\") = " << abc->accepts2("caaaaaaaaaaaaaaad") << endl;
  cout << "abc->accepts3(\"caaaaaaaaaaaaaaad\") = " << abc->accepts3("caaaaaaaaaaaaaaad") << endl;

  delete abc;
  delete fab;

  #pragma endregion HUE3A

  #pragma region HUE3B

  cout << "3.b)" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("S").
    addFinalState("R").
    addTransition("S", 'a', "S").
    addTransition("S", 'b', "S").
    addTransition("S", 'c', "S").
    addTransition("S", 'a', "A").
    addTransition("S", 'b', "B").
    addTransition("S", 'c', "C").
    addTransition("A", 'a', "A").
    addTransition("A", 'b', "A").
    addTransition("A", 'c', "A").
    addTransition("B", 'a', "B").
    addTransition("B", 'b', "B").
    addTransition("B", 'c', "B").
    addTransition("C", 'a', "C").
    addTransition("C", 'b', "C").
    addTransition("C", 'c', "C").
    addTransition("A", 'a', "R").
    addTransition("B", 'b', "R").
    addTransition("C", 'c', "R");

  abc = fab->buildNFA();
  
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts1(\"cabcabcabcabcc\") = " << abc->accepts1("cabcabcabcabcc") << endl;
  });
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts2(\"cabcabcabcabcc\") = " << abc->accepts2("cabcabcabcabcc") << endl;
  });
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts3(\"cabcabcabcabcc\") = " << abc->accepts3("cabcabcabcabcc") << endl;
  });
  
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts1(\"caaaaaaaaaaaaaaad\") = " << abc->accepts1("caaaaaaaaaaaaaaad") << endl;
  });
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts2(\"caaaaaaaaaaaaaaad\") = " << abc->accepts2("caaaaaaaaaaaaaaad") << endl;
  });
  TimeAccept(abc, [](NFA* abc) {
    cout << "abc->accepts3(\"caaaaaaaaaaaaaaad\") = " << abc->accepts3("caaaaaaaaaaaaaaad") << endl;
  });

  delete abc;
  delete fab;

  #pragma endregion HUE3B

  #pragma region HUE3C

  cout << "3.b)" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("S").
    addFinalState("R").
    addTransition("S", 'a', "S").
    addTransition("S", 'b', "S").
    addTransition("S", 'c', "S").
    addTransition("S", 'a', "A").
    addTransition("S", 'b', "B").
    addTransition("S", 'c', "C").
    addTransition("A", 'a', "A").
    addTransition("A", 'b', "A").
    addTransition("A", 'c', "A").
    addTransition("B", 'a', "B").
    addTransition("B", 'b', "B").
    addTransition("B", 'c', "B").
    addTransition("C", 'a', "C").
    addTransition("C", 'b', "C").
    addTransition("C", 'c', "C").
    addTransition("A", 'a', "R").
    addTransition("B", 'b', "R").
    addTransition("C", 'c', "R");

  abc = fab->buildNFA();
  DFA* abcDfa = abc->dfaOf();

  vizualizeFA("abcDfa", abcDfa);  

  vizualizeFA("abc", abc);  

  delete abcDfa;
  delete abc;
  delete fab;

  #pragma endregion HUE3C

  #pragma region HUE3D

  cout << "3.b)" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder();
  fab->setStartState("S").
    addFinalState("R").
    addTransition("S", 'a', "S").
    addTransition("S", 'b', "S").
    addTransition("S", 'c', "S").
    addTransition("S", 'a', "A").
    addTransition("S", 'b', "B").
    addTransition("S", 'c', "C").
    addTransition("A", 'a', "A").
    addTransition("A", 'b', "A").
    addTransition("A", 'c', "A").
    addTransition("B", 'a', "B").
    addTransition("B", 'b', "B").
    addTransition("B", 'c', "B").
    addTransition("C", 'a', "C").
    addTransition("C", 'b', "C").
    addTransition("C", 'c', "C").
    addTransition("A", 'a', "R").
    addTransition("B", 'b', "R").
    addTransition("C", 'c', "R");

  abc = fab->buildNFA();
  abcDfa = abc->dfaOf();
  DFA* abcDfaMinimal = abcDfa->minimalOf();

  vizualizeFA("abcDfa", abcDfa);  

  vizualizeFA("abcDfaMinimal", abcDfaMinimal);  

  delete abcDfaMinimal;
  delete abcDfa;
  delete abc;
  delete fab;

  #pragma endregion HUE3D
/*
  cout << "2. NFA" << endl;
  cout << "------" << endl;
  cout << endl;

  fab = new FABuilder( // Floyd, Beigel: The Language of Machines, p. 255
          "-> 1 -> a 2 | b 1        \n\
           () 2 -> a 2 | b 1 | b 3  \n\
              3 -> a 2 | b 4        \n\
           () 4 -> a 4 | b 4");
  nfa = fab->buildNFA();
  delete fab;

  cout << "nfa:" << endl << *nfa;
  vizualizeFA("nfa", nfa);

  cout << "nfa->accepts1(\"abba\") = " << nfa->accepts1("abba") << endl;
  cout << "nfa->accepts2(\"abba\") = " << nfa->accepts2("abba") << endl;
  cout << "nfa->accepts3(\"abba\") = " << nfa->accepts3("abba") << endl;
  cout << "nfa->accepts1(\"bbab\") = " << nfa->accepts1("bbab") << endl;
  cout << "nfa->accepts2(\"bbab\") = " << nfa->accepts2("bbab") << endl;
  cout << "nfa->accepts3(\"bbab\") = " << nfa->accepts3("bbab") << endl;
  cout << endl;

  cout << "transforming nfa to dfaOfNfa ..." << endl;
  dfaOfNfa = nfa->dfaOf();
  cout << "dfaOfNfa:" << endl << *dfaOfNfa;
  vizualizeFA("dfaOfNfa", dfaOfNfa);

  cout << "minimizing dfaOfNfa to minDfaOfNfa ..." << endl;
  minDfaOfNfa = dfaOfNfa->minimalOf();
  cout << "minDfaOfNfa:" << endl << *minDfaOfNfa;
  vizualizeFA("minDfaOfNfa", minDfaOfNfa);

  cout << "renaming minDfaOfNfa to renMinDfaOfNfa ..." << endl;
  renMinDfaOfNfa = minDfaOfNfa->renamedOf();
  cout << "renMinDfaOfNfa:" << endl << *renMinDfaOfNfa;
  vizualizeFA("renMinDfaOfNfa", renMinDfaOfNfa);
*/

} catch(const exception &e) {
  cerr <<  "EXCEPTION (" << typeid(e).name() << "): " << e.what() << endl;
} // catch

  // fab has already been deleted
  //delete dfa;
  //delete nfa;
  //delete dfaOfNfa ;
  //delete minDfaOfNfa;
  //delete renMinDfaOfNfa;

  cout << endl;
  cout << "END Main" << endl;

  return 0;

} // main


// end of Main.cpp
//======================================================================
