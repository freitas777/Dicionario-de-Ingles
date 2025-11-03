#include "../include/Dictionary.hpp"
#include <iostream>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

Dictionary::Dictionary() {
    this->root = nullptr;
    this->nodeCount = 0;
    srand(time(0));
}

Dictionary::~Dictionary() {
    destroyTree(root);
}

void Dictionary::destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Dictionary::initializeFromWordList(WordList& wordList) {
    while (wordList.size > 0) {
        int randomPos = rand() % wordList.size;
        Word word = wordList.remove(randomPos);
    
        treeInsert(word);
    }
}

Dictionary::BSTNode* Dictionary::treeSearch(BSTNode* currentNode, string key) {
    if (currentNode == nullptr || key == currentNode->word.getEnglish()) {
        return currentNode;
    }
    
    if (key < currentNode->word.getEnglish()) {
        return treeSearch(currentNode->left, key);
    } else {
        return treeSearch(currentNode->right, key);
    }
}

Word* Dictionary::treeSearch(string english) {
    BSTNode* result = treeSearch(root, english);
    
    if (result != nullptr) {
        return &(result->word);
    }
    
    return nullptr;
}

Dictionary::BSTNode* Dictionary::treeMinimum(BSTNode* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void Dictionary::treeInsert(Word word) {
    BSTNode* wordNode = new BSTNode(word);
    
    BSTNode* parentNode = nullptr;
    BSTNode* currentNode = this->root;  
    
    while (currentNode != nullptr) {
        parentNode = currentNode;
        if (wordNode->word.getEnglish() < currentNode->word.getEnglish()) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    
    wordNode->parent = parentNode;
    
    if (parentNode == nullptr) {
        this->root = wordNode;
    } else if (wordNode->word.getEnglish() < parentNode->word.getEnglish()) {
        parentNode->left = wordNode;
    } else {
        parentNode->right = wordNode;
    }

    nodeCount++;
}

void Dictionary::transplant(BSTNode* nodeToReplace, BSTNode* replacementNode) {
    if (nodeToReplace->parent == nullptr) {
        this->root = replacementNode;
    } else if (nodeToReplace == nodeToReplace->parent->left) {
        nodeToReplace->parent->left = replacementNode;
    } else {
        nodeToReplace->parent->right = replacementNode;
    }
    
    if (replacementNode != nullptr) {
        replacementNode->parent = nodeToReplace->parent;
    }
}

void Dictionary::treeDelete(BSTNode* nodeToDelete) {
    if (nodeToDelete->left == nullptr) {
        transplant(nodeToDelete, nodeToDelete->right);
    } else if (nodeToDelete->right == nullptr) {
        transplant(nodeToDelete, nodeToDelete->left);
    } else {
        BSTNode* sucessor = treeMinimum(nodeToDelete->right);
        
        if (sucessor->parent != nodeToDelete) {
            transplant(sucessor, sucessor->right);
            sucessor->right = nodeToDelete->right;
            sucessor->right->parent = sucessor;
        }
        
        transplant(nodeToDelete, sucessor);
        sucessor->left = nodeToDelete->left;
        sucessor->left->parent = sucessor;
    }
    
    delete nodeToDelete;
    nodeCount--;
}

bool Dictionary::remove(string english) {
    BSTNode* wordNode = treeSearch(root, english);
    
    if (wordNode == nullptr) {
        return false;
    }
    
    treeDelete(wordNode);
    return true;
}

void Dictionary::inorderTreeWalk(BSTNode* node) {
    if (node != nullptr) {
        inorderTreeWalk(node->left);
        cout << node->word.getEnglish() << " ";
        inorderTreeWalk(node->right);
    }
}

void Dictionary::printInOrder() {
    cout << "\n=== Percurso Em-Ordem ===" << endl;
    inorderTreeWalk(root);
    cout << endl;
}

void Dictionary::printBreadthFirst() {
    if (root == nullptr) {
        cout << "Árvore vazia!" << endl;
        return;
    }
    
    cout << "\n=== Percurso Em Largura ===" << endl;
    
    queue<BSTNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        BSTNode* current = q.front();
        q.pop();
        
        cout << current->word.getEnglish() << " ";
        
        if (current->left != nullptr) {
            q.push(current->left);
        }
        
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    
    cout << endl;
}

int Dictionary::size() {
    return nodeCount;
}

bool Dictionary::isEmpty() {
    return root == nullptr;
}