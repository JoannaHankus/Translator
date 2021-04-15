//
// Created by proxpxd on 20.05.19.
//

#ifndef TRANSLATOR_LANGUAGE_HPP
#define TRANSLATOR_LANGUAGE_HPP

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
//#include <algorithm>

class Word;

class Language{
    static std::map<std::string, Language*> languages;
public:
    typedef std::map<std::string, Word> wordMap;
    typedef std::vector<Word>::iterator iterator;

private:
    std::string name;
    wordMap words;
    std::vector<Word> wordVector;

public:

    Language(std::string name);

    bool exists(const std::string &word) const;
    void addWord(const std::string &word);
    void addTranslation(Language *language, const std::string &word, const std::string &translation);
    void addTranslation( Language &language, const std::string &word, const std::string &translation);
    void addTranslation(const std::string &language, const std::string &word, const std::string &translation);

    Word& getWord(const std::string &word);
    std::vector<Word>& getWords();

    iterator begin();
    iterator end();
    size_t size() const;


    std::string toString() const;
    void showAll() const;

    friend std::ostream& operator<<(std::ostream &out, const Language &lang);

};

#endif //TRANSLATOR_LANGUAGE_HPP
