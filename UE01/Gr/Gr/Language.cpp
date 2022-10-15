// Language.h:                                            SWE, 2022
// ----------------
// Lengwidsch
//================================

#include <exception>

#include "Language.h"
#include "SymbolStuff.h"
#include "SequenceStuff.h"

std::ostream& operator <<(std::ostream& os, const Sentence& sentence) {
	os << "[ ";
	for (const TSymbol* word : sentence.words) {
		os << word->name << " ";
	}
	os << "]";
	return os;
}

bool operator ==(const Sentence& left, const Sentence& right) {
	if (left.words.size() != right.words.size()) return false;

	for (int i = 0; i < left.words.size(); i++)
	{
		if (left.words[i]->name != right.words[i]->name) return false;
	}

	return true;
}
bool operator <(const Sentence& left, const Sentence& right) {
	return left.words.size() < right.words.size();
}

Sentence::Sentence(const Sentence& language) {
	words = {};
	for (TSymbol* sy : language.words) {
		words.push_back(sy);
	}
}

void Sentence::addWord(TSymbol* word) {
	words.push_back(word);
}

size_t Sentence::length() const {
	return words.size();
}

std::ostream& operator <<(std::ostream& os, const Language& language) {
	os << "L(G(S)): {\n";
	for (const Sentence* sentence : language.sentences) {
		os << *sentence << "\n";
	}
	os << "}";
	return os;
}

void Language::addSentence(Sentence* sentence) {
	sentences.insert(sentence);
}

bool Language::hasSentence(Sequence* s) const {
	// convert sequence to sentence
	Sentence sentence{};
	for (Symbol* sy : *s) {
		if (sy->isNT())
			throw std::runtime_error("NT found in sentence");

		sentence.addWord(dynamic_cast<TSymbol*>(sy));
	}

	for (const Sentence* curr : sentences) {
		if (*curr != sentence) {
			return false;
		}
	}
	return true;
}

// end of GrammarBuilder.h
//======================================================================