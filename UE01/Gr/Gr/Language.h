// Language.h:                                            SWE, 2022
// ----------------
// Lengwidsch
//================================

#ifndef Language_h
#define Language_h

#include <vector>
#include <set>
#include <iostream>

class TSymbol;

class Sequence;

class Sentence {

	friend std::ostream& operator <<(std::ostream& os, const Sentence& sentence);
	friend bool operator ==(const Sentence& left, const Sentence& right);
	friend bool operator <(const Sentence& left, const Sentence& right);

	private:
		std::vector<TSymbol*> words{};

	public:
		Sentence() = default;
		Sentence(const Sentence &);
		Sentence(const Sentence &&) = delete;
		void addWord(TSymbol* word);
		size_t length() const;
};

class Language {

	friend std::ostream& operator <<(std::ostream& os, const Language& language);

	private:
		std::set<Sentence*> sentences{};

	public:
		Language() = default;
		Language(const Language&&) = delete;
		void addSentence(Sentence* sentence);
		bool hasSentence(Sequence* s) const;

};

#endif

// end of GrammarBuilder.h
//======================================================================