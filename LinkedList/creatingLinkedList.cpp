#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head;

void createList(int n) {
    int i;
    struct Node *q, *last;

    head = new Node;
    cout << "Enter val: ";
    cin >> head->data;
    head->next = NULL;  
    last = head;

    for(i=1; i<n;i++){
        q = new Node;
        cout << "Enter val: ";
        cin >> q->data;
        q->next = NULL;
        last->next = q;
        last = q;
    }
}

void displayList(struct Node *p){

    while(p!=NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, elem;    

    cout << "Enter number of elem: ";
    cin >> n;

    createList(n);
    displayList(head);
}