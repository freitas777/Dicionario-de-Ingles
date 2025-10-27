#include <iostream>
#include <string>
#include "Word.hpp"

using namespace std;

Word::Word(string english, string portuguese, string word_class) {
    this->english = english;
    this->portuguese = portuguese;
    this->word_class = word_class;
}

Word::getEnglish() {
    return this->english;
}

Word::getPortuguese() {
    return this->portuguese;
}

Word::getWordClass() {
    return this->word_class;
}

void Word::printWord() {
    cout << "English: " << this->english << endl;
    cout << "Portuguese: " << this->portuguese << endl;
    cout << "Word Class: " << this->word_class << endl;
}