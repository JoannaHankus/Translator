#include <iostream>

#include "Word.hpp"
#include "Language.hpp"


Word::Word() {
    this->name = "";
    this->language = nullptr;
    translationsVector = std::vector<Word*>();
    translations = languagesMap();
}

Word::Word(Language &language, const std::string &word) {
    this->name = word;
    this->language = &language;
    translationsVector = std::vector<Word*>();
    translations = languagesMap();
}

Word::Word(const Word &word) {
    this->name = word.toString();
    this->language = word.language;
    for(auto w: word.translationsVector){
        this->translationsVector.push_back(w);
    }

    for(auto lang: word.translations){
        for(auto w: lang.second){
            this->translations[lang.first][w.first] = w.second;
        }
    }

}


void Word::addTranslation(Language* translateTo, const std::string &translation){

    translateTo->addWord(translation);
    Word &translatedWord = translateTo->getWord(translation);

    //std::cout << "addT " << name << "|\n";
    //std::cout << translatedWord << "|\n";
    //std::cout << &translatedWord << "\n";

    if( translation == "enjoy"){
        std::cout << "";
        std::string lang = translateTo->toString();

    }

    translations[translateTo->toString()][&translatedWord] = 0;

    translationsVector.push_back(&translatedWord);

    if(!translatedWord.exists(language->toString(), this->toString())){
        translateTo->addTranslation(language->toString(), translation, this->toString());
    }

}

Word::languagesMap& Word::getLanguagesMap() {
    return translations;
}

/*
std::vector<Word*>& Word::getTranslations(const std::string &lang) {
    return wordVector;
}*/

bool Word::exists(const std::string &lang, const std::string &wordString) {
    for(auto pair: translations[lang]){
        if(pair.first->toString() == wordString) return true;
    }
    return false;
}

Word::iterator Word::begin() {
    translations.begin();
}

Word::iterator Word::end() {
    translations.end();
}


std::string Word::toString() const{
    return name;
}
/*
std::vector<Word*> Word::operator[](const std::string &lang) {
    return getTranslations(lang);
}*/


std::ostream& operator<<(std::ostream& out, const Word &word){
    return out << word.toString();
}
