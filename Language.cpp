//
// Created by proxpxd on 20.05.19.
//

#include "Language.hpp"
#include "Word.hpp"

std::map<std::string, Language*> Language::languages;

Language::Language(std::string name){
    this->name = name;
    languages[name] = this;

}

bool Language::exists(const std::string &word) const{
    return words.find(word) != words.end();
}


void Language::addWord(const std::string &word){
    if(!exists(word)){
        Word newWord = Word(*this, word);
        wordVector.push_back(newWord); //??
        words[word] = wordVector.back();
    }

    //this->showAll();
}

void Language::addTranslation(Language *language, const std::string &word, const std::string &translation) {
    addWord(word);
    words[word].addTranslation(language, translation);
}

void Language::addTranslation( Language &language, const std::string &word, const std::string &translation) {
    addTranslation(language.toString(), word, translation);
}

void Language::addTranslation(const std::string &language, const std::string &word, const std::string &translation){
    Language* lang = languages[language];
    addTranslation(lang, word, translation);
}

Word& Language::getWord(const std::string &word) {
    return words.find(word)->second;
}

std::vector<Word>& Language::getWords() {
    return wordVector;
}

Language::iterator Language::begin() {
    return wordVector.begin();
}

Language::iterator Language::end() {
    return wordVector.end();
}

size_t Language::size() const{
    return words.size();
}


std::string Language::toString() const{
    return name;
}

void Language::showAll() const {
    std::cout << name << ":\n";
    for(auto [wordName, word]: words){ //C17 deklaracje rozpakowywujące
        std::cout << "  " << wordName << ": {";
        for(auto [langName, translations]: word){
            std::cout << "{ " << langName << ": ";
            for(auto [translation, num]: translations){
                std::cout << *translation << ", ";
            }
            std::cout << "}, ";
        }
        std::cout << "}\n";
    }
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream &out, const Language &lang) {
    return out << lang.toString();
}