// Arquivo de implementação
#include "Stack.hpp"

Stack::Stack() {
    this->size = 0;
    this->top = nullptr;
}

Stack::~Stack() {
    // desalocar
    Node * temp = this->top;
    Node * tempNext;
    
    while(temp != nullptr) {
        tempNext = temp->next;
        delete temp;
        temp = tempNext;
    }
}

int Stack::getSize() const {
    return this->size;
}

bool Stack::isEmpty() const {
    return this->top == nullptr;
}

void Stack::push(int value) {
    Node * node = new Node();  // alocação de memória
    node->data = value;

    node->next = this->top;
    this->top = node;

    this->size++;
}

Node * Stack::pop() {
    if (!isEmpty()) {
        Node * temp;
        temp = top;
        top = top->next;

        this->size--;
        temp->next = nullptr;
        return temp;
    }

    return nullptr;
}

void Stack::printNodes() const {
    Node * ptr = this->top;

    std::cout << "\n STACK: ";
    while(ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
}