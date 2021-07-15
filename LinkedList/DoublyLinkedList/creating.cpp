#include<iostream>
using namespace std;

class Node {
    public:
        Node *prev;
        int data;
        Node *next;
};

class DoublyLinkedList{
    private:
        Node *head;

    public:
        DoublyLinkedList(){
            head = NULL;
        }
        DoublyLinkedList(int A[], int n){
            Node *last, *q;
            head = new Node;
            head->prev = NULL;
            head->data = A[0];
            head->next = NULL;
            last = head;

            for (int i = 1; i < n;i++){
                q = new Node;
                q->prev = last;
                q->data = A[i];
                q->next = last->next;
                last->next = q;
                last = last->next;
            }
        }
        void Display();
        void DisplayRev();
        ~DoublyLinkedList();
};

void DoublyLinkedList::Display(){
    Node *p = head;
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DoublyLinkedList::DisplayRev(){
    Node *p = head;
    while(p->next!=NULL){
        p = p->next;
    }
    while(p!=NULL){
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node *p = head;
    Node *q;
    while(p!=NULL){
        q = p;
        p = p->next;
        delete q;
    }
}

int main() {
    int arr[] = {1, 4, 8, 9};
    DoublyLinkedList lst(arr, 4);
    lst.Display();
    lst.DisplayRev();

    return 0;
}