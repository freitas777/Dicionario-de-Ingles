#include "../include/WordList.hpp"
#include <iostream>

using namespace std;

WordList::WordList() {
    this->head = NULL;
    this->tail = NULL;
    this->size = 0;
}

WordList::~WordList() {
    Node * temp = this->head;
    Node * tempNext;
    
    while(temp != nullptr) {
        tempNext = temp->next;
        delete temp;
        temp = tempNext;
    }
}

void WordList::add(Word word) {
    Node * node = new Node();

    if (this->head == NULL) {
        this->head = node;
        this->tail = node;
        node->next = nullptr;
        node->prev = nullptr;
    } else {
        this->tail->next = node;
        node->prev = this->tail;
        node->next = nullptr;
        this->tail = node;
    }

    node->word = word;
    this->size++;
}

Word WordList::remove(int pos) {
    int counter = 0;
    Word removedWord;
    if (pos <= this->size/2) {
        Node * ptr = this->head;
        while (counter < pos) {
            counter++;
            ptr = ptr->next;           
        }
        if (ptr == this->head) {
            this->head = ptr->next;
            if (this->head != nullptr) {
                this->head->prev = nullptr;
            }
        } else if (ptr == this->tail) {
            this->tail = ptr->prev;
            if (this->tail != nullptr) {
                this->tail->next = nullptr;
            }
        } else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }

        removedWord = ptr->word;
        delete ptr;
        this->size--;
        return removedWord;
    } else {
        int counter = this->size;
        Node * ptr = this->tail;
        while (counter > pos) {
            counter--;
            ptr = ptr->prev;
        }
        if (ptr == this->tail) {
            this->tail = ptr->prev;
            if (this->tail != nullptr) {
                this->tail->next = nullptr;
            }
        } else if (ptr == this->head) {
            this->head = ptr->next;
            if (this->head != nullptr) {
                this->head->prev = nullptr;
            }
        } else {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }

        removedWord = ptr->word;
        delete ptr;
        this->size--;
        return removedWord;
    }
    
    return removedWord;
}

void WordList::print() {
    Node * ptr = this->head;

    while(ptr != nullptr) {
        ptr->word.printWord();
        ptr = ptr->next;
    }
}