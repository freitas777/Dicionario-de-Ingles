#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include "WordList.hpp"
#include <string>
using namespace std;

class FileReader {
    public:
        FileReader();
        WordList readWords(string path);
};

#endif