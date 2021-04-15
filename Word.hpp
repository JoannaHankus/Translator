#ifndef TRANSLATOR_WORD_HPP
#define TRANSLATOR_WORD_HPP

#include <iostream>
#include <vector>
#include <map>
//#include "Language.hpp"

class Language;

class Word {
public:
    typedef std::map<Word*, size_t > wordScores;
    typedef std::map<std::string, wordScores> languagesMap;
    typedef languagesMap::iterator iterator;

private:
    std::string name;
    Language *language;
    languagesMap translations;
    std::vector<Word*> translationsVector;

public:

    Word();
    Word(Language &language, const std::string &word);
    Word(const Word &word);
    void addTranslation(Language* translateTo, const std::string &translation);
    languagesMap& getLanguagesMap();
    std::vector<Word*>& getTranslations(const std::string &lang);

    bool exists(const std::string &lang, const std::string &wordString);

    iterator begin();
    iterator end();


    std::string toString() const;

    std::vector<Word*> operator[](const std::string &lang);
    friend std::ostream& operator<<(std::ostream& out, const Word &word);
};

#endif //TRANSLATOR_WORD_HPP
