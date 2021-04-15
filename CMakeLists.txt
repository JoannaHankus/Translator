cmake_minimum_required(VERSION 3.13)
project(translator)

set(CMAKE_CXX_STANDARD 14)

add_executable(translator main.cpp Language.hpp Language.cpp Word.hpp Word.cpp tests/WordTest.cpp tests/WordTest.hpp tests/LanguageTest.cpp tests/LanguageTest.hpp)