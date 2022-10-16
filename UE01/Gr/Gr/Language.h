// Language.h:                                            SWE, 2022
// ----------------
// Lengwidsch
//================================

#ifndef Language_h
#define Language_h

#include <vector>
#include <set>
#include <iostream>

class Sequence;

class Language {

	friend std::ostream& operator <<(std::ostream& os, const Language& language);

	private:
		std::set<Sequence*> sentences{};
		int maxLength;

	public:
		Language(int maxLength);

		Sequence& at(int i) const;
		void addSentence(Sequence* s);
		bool hasSentence(Sequence* s) const;

};

#endif

// end of GrammarBuilder.h
//======================================================================