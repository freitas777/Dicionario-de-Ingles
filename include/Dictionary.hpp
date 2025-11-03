#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include "Word.hpp"
#include "WordList.hpp"
#include <string>

using namespace std;

class Dictionary {
private:
    struct BSTNode {
        Word word;
        BSTNode* left;
        BSTNode* right;
        BSTNode* parent;
        
        BSTNode(Word w) : word(w), left(nullptr), right(nullptr), parent(nullptr) {}
    };
    
    BSTNode* root;
    int nodeCount;
    
    BSTNode* treeSearch(BSTNode* x, string k);
    BSTNode* treeMinimum(BSTNode* x);
    void transplant(BSTNode* u, BSTNode* v);
    void inorderTreeWalk(BSTNode* x);
    void destroyTree(BSTNode* node);
    
public:
    Dictionary();
    ~Dictionary();
    
    void initializeFromWordList(WordList& wordList);
    
    void treeInsert(Word word);
    Word* treeSearch(string english);
    void treeDelete(BSTNode* z);
    bool remove(string english);
    
    void printInOrder();
    void printBreadthFirst(); 
    
    int size();
    bool isEmpty();
};

#endif