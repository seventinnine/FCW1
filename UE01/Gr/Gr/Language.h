// Language.h:                                            SWE, 2022
// ----------------
// Lengwidsch
//================================

#ifndef Language_h
#define Language_h

#include <vector>
#include <set>
#include <iostream>
#include "ObjectCounter.h"
#include "SequenceStuff.h"

class Language :
	private ObjectCounter<Language> {

	friend std::ostream& operator <<(std::ostream& os, const Language& language);

	private:
		SequenceSet sentences{};
		int maxLength;

	public:
		Language(int maxLength);

		Sequence& at(int i) const;
		void addSentence(Sequence* s);
		bool hasSentence(Sequence* s) const;
};

#endif

// end of Language.h
//======================================================================