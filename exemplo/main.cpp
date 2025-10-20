#include "Stack.hpp"


int main(void) {
    Stack stack = Stack();

    stack.push(5);
    stack.push(3);
    stack.push(10);

    stack.printNodes();

    Node * node = stack.pop();
    //node->next->data = 100;

    if(node != nullptr) {
        std::cout << " Popped element: " << node->data;
    }    

    std::cout << "\n Number of elements: " << stack.getSize();
    stack.printNodes();

    stack.push(15);
    stack.printNodes();

    return 0;
}