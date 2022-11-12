// MooreDFA.cpp:                                                SWE, 2022
// -------
// Objects of class MooreDFA represent deterministic finite automata.
//======================================================================

#include <cmath>
#include <cstring>

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

using namespace std;

#include "TapeStuff.h"
#include "StateStuff.h"
#include "MbMatrix.h"
#include "FABuilder.h"
#include "MooreDFA.h"

// --- implementation of class MooreDFA ---

MooreDFA::MooreDFA(const StateSet &S,  const TapeSymbolSet &V,
         const State    &s1, const StateSet      &F,
         const DDelta   &delta,
         const std::map<State, char> &mooreLambda)
: DFA(S, V, s1, F, delta), mooreLambda(mooreLambda) {
} // MooreDFA::MooreDFA

bool MooreDFA::accepts(const Tape &tape) const {
  int        i   = 0;       // index of first symbol
  TapeSymbol tSy = tape[i]; // fetch first tape symbol
  State      s   = s1;      // start state
  cout << mooreLambda.at(s);
  while (tSy != eot) {      // eot = end of tape
    s = delta[s][tSy];
    if (!defined(s))
      return false;         // s undefined, so no acceptance
    cout << mooreLambda.at(s);
    i++;
    tSy = tape[i];          // fetch next symbol
  } // while
  cout << " ";
  return F.contains(s);     // accepted <==> s element of F
} // MooreDFA::accepts


// end of MooreDFA.cpp
//======================================================================
