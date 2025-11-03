#ifndef WORDLIST_HPP
#define WORDLIST_HPP

#include "Word.hpp"

class WordList {
    public:
        struct Node {
            Word word;
            Node * next;
            Node * prev;
        };
        
        Node * head;
        Node * tail;
        int size;

    public:
        WordList();
        ~WordList();
        
        void add(Word word);
        Word remove(int pos);
        void print();
};

#endif