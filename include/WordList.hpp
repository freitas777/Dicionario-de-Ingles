#ifndef __WORD_LIST_HPP__
#define __WORD_LIST_HPP__

#include "Word.hpp"
using namespace std;

struct Node {
    Word word;
    Node * next;
    Node * prev;
};

class WordList {
    private:
        Node * head;
        Node * tail;
        int size;

    public:
        WordList();
        ~WordList();

        void add(Word word);
        void remove(Word word);
        void print();
};

#endif