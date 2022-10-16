// Main.cpp:                                             HDO, 2004-2022
// --------
// Main program for the object-oriented representation of formal
// languages using classes for symbols, sequences and grammars.
// ====================================================================

#include <cstdio>

#include <iostream>
#include <typeinfo>

using namespace std;

#include "SignalHandling.h"
#include "Timer.h"
#include "SymbolStuff.h"
#include "SequenceStuff.h"
#include "Vocabulary.h"
#include "GrammarBasics.h"
#include "GrammarBuilder.h"
#include "Grammar.h"
#include "Language.h"

// Activation (with 1) allows simple builds via command line
// * for GNU   use:  g++      -std=c++17 Main.cpp
// * for Clang use:  clang++  -std=c++17 Main.cpp
// * for M.S.  use:  cl /EHsc /std:c++17 Main.cpp
#if 0
#include "SignalHandling.cpp"
#include "Timer.cpp"
#include "SymbolStuff.cpp"
#include "SequenceStuff.cpp"
#include "GrammarBasics.cpp"
#include "GrammarBuilder.cpp"
#include "Grammar.cpp"
#include "Language.cpp"
#endif


Grammar* newEpsilonFreeGrammarOf(Grammar* g) {
    // step 1
    VNt deletable = g->deletableNTs();

    // step 2

    // use symbolpool to get instances by name 
    // (symbols from initial creation are still stored in SymbolPoolData)
    SymbolPool sp{};
    GrammarBuilder gb{g->root}; // reuse old root for now

    // for each rule
    // c++20 structureed binding
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
            }
        }
    }

    // step 3
    if (deletable.contains(g->root)) {
        // add S' (or rather name of original root node + ')
        NTSymbol* newRoot = sp.ntSymbol(g->root->name + "'");
        gb.addRule(newRoot, { new Sequence({g->root}), new Sequence() /* eps */});
        gb.setNewRoot(newRoot);
    }

    return gb.buildGrammar();
}

void languageOfRecursive(
    Language * language, 
    const RulesMap & rules, 
    const SequenceSet& sequences, 
    // copy ctor of Sequence copies the collection, making use of call stack
    Sequence currSentence, 
    int maxLen
) {
    if (currSentence.length() >= maxLen) return;

    for (const Sequence* rule : sequences) {
        // look at each symbol of current rule (alternative)
        for (Symbol* sy : *rule) {
            if (sy->isNT()) {
                // go to coresponding NTSymbol in the RulesMap
                NTSymbol* ntSy = dynamic_cast<NTSymbol*>(sy); // cannot be null
                languageOfRecursive(language, rules, rules[ntSy], currSentence, maxLen);
            }
            else {
                // add TSymbol to current sentence
                currSentence.append(sy);
            }
        }
        if (currSentence.length() <= maxLen) {
            // copy is necessary here because otherwise
            // we would get the TSymbols of the next alternative
            // in the previously added sentence (which we don't want)
            language->addSentence(new Sequence(currSentence));
        }
    }
}

Language* languageOf(const Grammar* g, int maxLen) {
    Language* language = new Language(maxLen);
    Sequence s{};
    languageOfRecursive(language, g->rules, g->rules[g->root], s, maxLen);
    return language;
}

int main(int argc, char* argv[]) {

    installSignalHandlers();

    cout << "START Main" << endl << endl;
    startTimer();

    try {

        SymbolPool* sp = new SymbolPool();
        cout << *sp << endl;

        GrammarBuilder* gb1 = nullptr;
        GrammarBuilder* gb2 = nullptr;
        GrammarBuilder* gb3 = nullptr;

        Grammar* g1 = nullptr;
        Grammar* g2 = nullptr;
        Grammar* g3 = nullptr;


        // *** test case selection: 1, 2, or 3 ***
#define TESTCASE 4

// ***************************************

        cout << "TESTCASE " << TESTCASE << endl << endl;

#if TESTCASE == 1 // programmatical grammar construction

        // G(S):
        // S -> A ;
        // A -> a B | B B b
        // B -> b | a b

        NTSymbol* S = sp->ntSymbol("S");
        NTSymbol* A = sp->ntSymbol("A");
        NTSymbol* B = sp->ntSymbol("B");

        TSymbol* a = sp->tSymbol("a");
        TSymbol* b = sp->tSymbol("b");
        TSymbol* sc = sp->tSymbol(";");

        gb1 = new GrammarBuilder(S);

#if 0 // with separate Sequence variables ...

        Sequence* seq1 = new Sequence({ A, sc });
        Sequence* seq2 = new Sequence({ a, B });
        Sequence* seq3 = new Sequence({ B, B, b });
        Sequence* seq4 = new Sequence(b);
        Sequence* seq5 = new Sequence({ a, b });

        gb1->addRule(S, seq1);
        gb1->addRule(A, { seq2, seq3 });
        gb1->addRule(B, { seq4, seq5 });

#else // .. much simpler with Sequences constructed in place

        gb1->addRule(S, new Sequence({ A, sc }));
        gb1->addRule(A, { new Sequence({a, B}),
                         new Sequence({B, B, b}) });
        gb1->addRule(B, { new Sequence(b),
                         new Sequence({a, b}) });
#endif

        g1 = gb1->buildGrammar();
        cout << "grammar constructed programmatically:" << endl << *g1 << endl;


#elif TESTCASE == 2 // grammar construction from text file

        gb2 = new GrammarBuilder(string("G.txt"));
        g2 = gb2->buildGrammar();
        // or for short: g2 = GrammarBuilder(string("G.txt")).buildGrammar();

        cout << "grammar from text file:" << endl << *g2 << endl;       
    

#elif TESTCASE == 3 // grammar construction from C string literal

        gb3 = new GrammarBuilder(
            "G(S):                          \n\
     S -> E ;                       \n\
     E -> a A b E | b B a E | eps   \n\
     A -> a A b A | eps             \n\
     B -> b B a B | eps             ");
        g3 = gb3->buildGrammar();
        // or for short: g3 = GrammarBuilder("...").buildGrammar();

        cout << "grammar from C string:" << endl << *g3 << endl;

#elif TESTCASE == 4

        gb2 = new GrammarBuilder(string("G1.txt"));
        g2 = gb2->buildGrammar();
        Grammar* epsilonFree = newEpsilonFreeGrammarOf(g2);
        // or for short: g2 = GrammarBuilder(string("G.txt")).buildGrammar();

        cout << "grammar from text file:" << endl << *g2 << endl;
        cout << "newEpsilonFreeGrammarOf(g2):" << endl << *epsilonFree << endl;


#elif TESTCASE == 5

        gb2 = new GrammarBuilder(string("G23.txt"));
        g2 = gb2->buildGrammar();
        Grammar* epsilonFree = newEpsilonFreeGrammarOf(g2);

        Language* languageG2 = languageOf(epsilonFree, 6);
        Sequence& s1 = languageG2->at(1);
        Sequence madeUpSequence{ 
            sp->symbolFor("a"), 
            sp->symbolFor("a"), 
            sp->symbolFor("a"), 
            sp->symbolFor("b") 
        };
        Sequence madeUpSequenceNotContained{ 
            sp->symbolFor("a"), 
            sp->symbolFor("b"), 
            sp->symbolFor("b"), 
            sp->symbolFor("b") 
        };

        cout << "grammar from text file:" << endl << *g2 << endl;
        cout << "newEpsilonFreeGrammarOf(g2):" << endl << *epsilonFree << endl;
        cout << "language(g2):" << endl << *languageG2 << endl;
        cout << "s1: " << s1 << endl;
        cout << "languageG2.hasSentence(s1): " << boolalpha 
            << languageG2->hasSentence(&s1) << endl;
        cout << "madeUpSequence: " << madeUpSequence << endl;
        cout << "languageG2.hasSentence(madeUpSequence): " << boolalpha 
            << languageG2->hasSentence(&madeUpSequence) << endl;
        cout << "madeUpSequence: " << madeUpSequenceNotContained << endl;
        cout << "languageG2.hasSentence(madeUpSequenceNotContained): " << boolalpha 
            << languageG2->hasSentence(&madeUpSequenceNotContained) << endl;

#else // none of the TESTCASEs above

        cerr << "ERROR: invalid TESTCASE " << TESTCASE << endl;

#endif

        delete gb1;
        delete gb2;
        delete gb3;

        delete g1;
        delete g2;
        delete g3;

        cout << endl << *sp << endl; // final contents of symbol pool
        delete sp;

    }
    catch (const exception& e) {
        cerr << "ERROR (" << typeid(e).name() << "): " << e.what() << endl;
    } // catch

    stopTimer();
    cout << "elapsed time: " << elapsed() << endl;
    cout << endl;
    cout << "END Main" << endl;

    // cout << "type CR to continue ...";
    // getchar();

    return 0;
} // main


// end of Main.cpp
//======================================================================
