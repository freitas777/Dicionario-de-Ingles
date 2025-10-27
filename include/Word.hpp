#ifndef _WORD_HPP_
#define _WORD_HPP_

#include <string>
using namespace std;

class Word {
    private: 
        string english;
        string portuguese;
        string word_class;

    public:
        Word();

        string getEnglish();
        string getPortuguese();
        string getWordClass();

        void printWord();
}

#endif