#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class CircularLinkedList {
    private:
        Node *head;
    public:
        CircularLinkedList(){
            head = NULL;
        }
        CircularLinkedList(int A[], int n);
        void Display();
        int Length();
        ~CircularLinkedList();
};

CircularLinkedList::CircularLinkedList(int A[], int n) {
    Node *q, *last;

    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;
    
    for (int i = 1; i < n; i++){
        q = new Node;
        q->data = A[i];
        q->next = last->next;
        last->next = q;
        last = last->next;
    }

    last->next = head;
}

void CircularLinkedList::Display() {
    Node *p = head;
    do {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
    cout << endl;
}

int CircularLinkedList::Length() {
    Node *p = head;
    int len = 0;
    do {
        len++;
        p = p->next;
    } while (p != head);
    cout << endl;
    return len;
}

CircularLinkedList::~CircularLinkedList(){
    Node *p = head;
    do {
        head = head->next;
        delete p;
        p = head;
    } while (p != head);
}

int main() {
    int arr[] = {2, 3, 4, 1};
    CircularLinkedList lst(arr, 4);
    lst.Display();
    return 0;
}

