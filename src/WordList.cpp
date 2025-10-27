#include "WordList.hpp"

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
    } else {
        this->tail->next = node;
        this->node->prev = this->tail;
        this->tail = node;
    }

    node->word = word;
    this->size++;
}

Word WordList::remove(Word word, int pos) {
    if (pos <= this->size/2) {
        Node * ptr = this->head;
        while (ptr != nullptr) {
            if (ptr->word.getEnglish() == word.getEnglish()) {
                if (ptr == this->head) {
                    this->head = ptr->next;
                    this->head->prev = nullptr;
                } else {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }

                delete ptr;
                this->size--;
                return word;
            } else {
                ptr = ptr->next;
            }
        }
    } else {
        Node * ptr = this->tail;
        while (ptr != nullptr) {
            if (ptr->word.getEnglish() == word.getEnglish()) {
                if (ptr == this->tail) {
                    this->tail = ptr->prev;
                    this->tail->next = nullptr;
                } else {
                    ptr->prev->next = ptr->next;
                    ptr->next->prev = ptr->prev;
                }

                delete ptr;
                this->size--;
                return word;
            } else {
                ptr = ptr->prev;
            }
        }
    }
}

void WordList::print() {
    Node * ptr = this->head;

    while(ptr != nullptr) {
        ptr->word.printWord();
        ptr = ptr->next;
    }
}