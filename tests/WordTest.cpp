//
// Created by proxpxd on 20.05.19.
//

#include <cassert>
#include "../Word.hpp"
#include "../Language.hpp"


void toStringTest(){
    Language lang("test");
    auto word = Word(lang, "hamburger");
    std::string text = word.toString();
    assert(text == "hamburger");
    std::cout << "String test passed!\n";
}

void testWord(){
    toStringTest();
    std::cout << "@Word test passed!\n";
}