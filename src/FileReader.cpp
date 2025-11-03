#include "../include/FileReader.hpp"
#include "../include/Word.hpp"
#include "../include/WordList.hpp"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

FileReader::FileReader() {}

WordList FileReader::readWords(string path) {
    ifstream file(path);
    string line;
    WordList wordList;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string english, portuguese, word_class;

        getline(ss, english, ',');
        getline(ss, portuguese, ',');
        getline(ss, word_class, ',');
        
        Word word(english, portuguese, word_class);
        wordList.add(word);
    }
    
    file.close();
    return wordList;
}