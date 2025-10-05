// queue implementation using linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;

public: 
    Queue() {
        head = tail = NULL;
    }

    void push(int data) {
        Node* newNode = new Node(data);

        if(empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        Node* temp;
        if(empty()) {
            return;
        } else {
            temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }
    }

    int front() {
        if(empty()) {
            return -1;
        } else {
            return head->data;
        }
    }

    bool empty() {
        return head == NULL;
    }
};

int main() {
    return 0;
}