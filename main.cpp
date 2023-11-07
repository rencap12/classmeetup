#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {data = val; next = nullptr;}
    Node(int val, Node* node) {data = val; next = node;}
};

class Stack_LL {
private:
    // topPtr points to the top element of the stack
    Node* toptr;
public:
    Stack_LL();
    ~Stack_LL();

    bool isEmpty() const;
    void push(int newItem);
    void pop();
    int peek() const;
};

Stack_LL::Stack_LL() {
    toptr = nullptr;

}

Stack_LL::~Stack_LL() {
    Node* curr = toptr;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    toptr = nullptr;
}

bool Stack_LL::isEmpty() const {
    /* Node* curr = toptr;
     int count = 0;
     while (curr->next != nullptr) {
         Node* temp = curr;
         curr = curr->next;
         ++count;
     }
     if(count == 0){
         return true;
     }
     else{
         return false;
     }
     */
    return toptr == nullptr;
}

void Stack_LL::push(int newItem) {
    Node* add = new Node(newItem, toptr);
    toptr = add;
    add = nullptr;
}

void Stack_LL::pop() {
    Node* temp = toptr;
    toptr = toptr->next;
    delete temp;
}

int Stack_LL::peek() const {
    return toptr->data;
}