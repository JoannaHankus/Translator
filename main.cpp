#include <iostream>
#include "Word.hpp"
#include "Language.hpp"

#include "tests/WordTest.hpp"
#include "tests/LanguageTest.hpp"


int main() {
    testWord();
    testLanguage();

    std::cout << "\n";

    Language pol("polish");
    Language eng("english");
    Language rus("russian");
    Language ger("german");

    pol.addWord("być");

    pol.addTranslation(eng.toString(), "lubić" ,"like");
    eng.addTranslation(pol, "do", "robić");
    pol.addTranslation(eng, "lubić", "enjoy");
    pol.addTranslation(eng, "pies", "dog");
    eng.addTranslation(pol, "like", "jak");

    pol.addTranslation(rus, "pies", "сабака");
    pol.addTranslation(ger, "pies", "Hund");

    pol.showAll();
    eng.showAll();
    rus.showAll();


    return 0;
}
