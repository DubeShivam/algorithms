// TYPES OF LINKED LISTS
// SINGLY // DOUBLY // CIRCULAR


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

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = tail = NULL;
    }

    void push_front(int data) {
        Node* newNode = new Node(data);
        if(head == NULL) {
            head = tail =  newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int data) {
        Node* newNode = new Node(data);
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if(tail == NULL) {
            return;
        }
        Node* temp = head; 
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void insert(int data, int pos) {
        Node* newNode = new Node(data);
        Node* temp = head;
        
        for(int i = 0; i < pos-1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    int search(int data) {
        Node* temp = head;
        int pos = 0;

        while(temp != NULL) {
            if(temp->data == data) {
                return pos;
            } 
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    void traverse() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList l;
    l.push_front(101);
    l.push_front(201);
    l.push_back(301);
    l.push_back(401);
    l.traverse();
    cout << endl;

    l.insert(701, 2);
    l.traverse();
    cout << endl;
    l.insert(801, 2);
    l.traverse();
    cout << endl;
    l.insert(501, 1);
    l.traverse();
    cout << endl;
    l.insert(1001, 3);
    l.traverse();
    cout << endl;

    cout << l.search(501) << " " << l.search(1001) << " " << l.search(2001);

    return 0;
}