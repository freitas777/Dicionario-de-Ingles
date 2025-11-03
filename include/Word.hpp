#ifndef WORD_HPP
#define WORD_HPP

#include <string>
using namespace std;

class Word {
    private:
        string english;
        string portuguese;
        string word_class;

    public:
        Word();
        Word(string english, string portuguese, string word_class);
        
        string getEnglish();
        string getPortuguese();
        string getWordClass();
        
        void printWord();
};

#endif