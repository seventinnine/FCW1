// MooreDFA.h:                                                 HDO, 2006-2019
// -----
// Objects of class MooreDFA represent deterministic finite automata.
//======================================================================

#ifndef MooreDFA_h
#define MooreDFA_h

#include "ObjectCounter.h"
#include "TapeStuff.h"
#include "StateStuff.h"
#include "DFA.h"


class FABuilder;           // forward for friend declaration only


class MooreDFA: public DFA
 /*OC+*/ , private ObjectCounter<MooreDFA> /*+OC*/ {

  friend class FABuilder;  // so FABuilder::build... methods can call prot. constr.

  private:

    typedef DFA Base;

  protected: // allows derived classes, e.g., for Mealy and or Moore

    // constructor called by FABuilder::build... methods and derived classes
    MooreDFA(const StateSet &S,  const TapeSymbolSet &V,
        const State    &s1, const StateSet      &F,
        const DDelta   &delta, 
        const std::map<State, char> &mooreLambda);

  public:
    const std::map<State, char> mooreLambda;
    MooreDFA(const MooreDFA  &mooredfa) = default;
    MooreDFA(      MooreDFA &&mooredfa) = default;

    virtual ~MooreDFA() = default;

    virtual bool accepts(const Tape &tape) const; // impl. of abstr. meth.

}; // DFA


#endif

// end of DFA.h
//======================================================================



