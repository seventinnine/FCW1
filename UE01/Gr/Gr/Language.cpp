// Language.h:                                            SWE, 2022
// ----------------
// Lengwidsch
//================================

#include <exception>

#include "Language.h"
#include "SymbolStuff.h"
#include "SequenceStuff.h"

std::ostream& operator <<(std::ostream& os, const Language& language) {
	os << "L(G(S)): maxLength=" << language.maxLength << " {\n";
	for (const Sequence* sentence : language.sentences) {
		os << *sentence << "\n";
	}
	os << "}";
	return os;
}

Sequence& Language::at(int idx) const {
	if (idx >= sentences.size() || idx < 0)
		throw std::invalid_argument("invalid index");
	auto it = sentences.cbegin();
	std::advance(it, idx);
	return **it;
}

Language::Language(int maxLength) 
	: maxLength{maxLength} {

}

void Language::addSentence(Sequence* s) {
	sentences.insert(s);
}

bool Language::hasSentence(Sequence* s) const {

	for (const Symbol* sy : *s) {
		if (sy->isNT())
			throw std::runtime_error("NT found in sentence");
	}

	for (const Sequence* curr : sentences) {
		// Sequence already has equality comparison (op ==) implemented
		if (*curr == *s) {
			return true;
		}
	}
	return false;
}

// end of GrammarBuilder.h
//======================================================================