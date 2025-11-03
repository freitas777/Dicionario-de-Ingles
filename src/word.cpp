#include <iostream>
#include <string>
#include "../include/Word.hpp"

using namespace std;

Word::Word() {
    this->english = "";
    this->portuguese = "";
    this->word_class = "";
}

Word::Word(string english, string portuguese, string word_class) {
    this->english = english;
    this->portuguese = portuguese;
    this->word_class = word_class;
}

string Word::getEnglish() { 
    return this->english;
}

string Word::getPortuguese() { 
    return this->portuguese;
}

string Word::getWordClass() { 
    return this->word_class;
}

void Word::printWord() {
    cout << "English: " << this->english << endl;
    cout << "Portuguese: " << this->portuguese << endl;
    cout << "Word Class: " << this->word_class << endl;
}