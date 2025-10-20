// Arquivo de definição da classe (cabeçalho)
#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>  // entrada e saída de dados
                     // via terminal

struct Node {
    int data;
    Node * next;
};

class Stack {
    private:
        int size;
        Node * top;

    public:
        Stack();
        ~Stack();

        int getSize() const;

        bool isEmpty() const; 

        void push(int value);
        Node * pop(); 

        void printNodes() const;
};

#endif