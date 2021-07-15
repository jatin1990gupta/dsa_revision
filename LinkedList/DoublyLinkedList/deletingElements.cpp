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
        void Delete(int pos);
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


void DoublyLinkedList::Delete(int pos){
    if(pos==1){
        Node *p=head;
        head = head->next;
        delete p;
    } else {
        Node *p=head;
        Node *q;
        for (int i = 0; i < pos - 1; i++){
            p = p->next;
        }
        q = p->prev;
        q->next = p->next;
        delete p;
    }
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
    lst.Delete(4);
    lst.Display();
    return 0;
}