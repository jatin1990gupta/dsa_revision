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
        void insert(int pos, int val);
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

void CircularLinkedList::insert(int pos, int val){
    Node *p = head;
    Node *q;

    if(pos==0) {
        while(p->next!=head){
            p = p->next;
        }
        q = new Node;
        q->data = val;
        p->next = q;
        q->next = head;
        head = q;
    } else {
        for (int i = 0; i < pos-1;i++){
            p = p->next;
        }
        q = new Node;
        q->data = val;
        q->next = p->next;
        p->next = q;
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
    lst.insert(2, 6);
    lst.Display();

    return 0;
}

