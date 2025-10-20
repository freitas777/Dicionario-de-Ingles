#include <string>
using namespace std;

class Word {
    private: 
        string english;
        string portuguese;
        string word_class;

    public:
        Word();
        ~Word();

        void printWord();

}