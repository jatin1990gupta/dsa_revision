#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

// Creating First List
void createFirst(int A[], int n) {
    Node *last, *q;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n;i++){
        q = new Node;
        q->data = A[i];
        q->next = last->next;
        last->next = q;
        last = last->next;
    }
}
// Creating Seconf List
void createSecond(int A[], int n) {
    Node *last, *q;

    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n;i++){
        q = new Node;
        q->data = A[i];
        q->next = last->next;
        last->next = q;
        last = last->next;
    }
}

void displayList(Node *p) {
    while(p!=NULL){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void ConcatLists(Node *p, Node *q){
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = q;
    q = second = NULL;
}


int main() {
    int A[] = {1, 5, 6, 9};
    int B[] = {3, 7, 10, 14};

    createFirst(A, 4);
    createSecond(B, 4);
    displayList(first);
    displayList(second);

    ConcatLists(first, second);
    displayList(first);

    return 0;
}
