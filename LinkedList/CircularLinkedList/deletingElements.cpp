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
        void Delete(int pos);
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

void CircularLinkedList::Delete(int pos) {
    if(pos==1){
        Node *p = head;
        Node *q;
        while(p->next!=head){
            p = p->next;
        }
        if(p==head){
            delete head;
            head = NULL;
        } else {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    } else {
        Node *p = head;
        Node *q;
        for (int i = 0; i < pos - 2;i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        delete q;
    }
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
    lst.Delete(4);
    lst.Display();

    return 0;
}

