#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head ;

void createList(int A[], int n) {
    Node *last, *q;

    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

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

// Reverse list by reversing links(using RECCURSION)
void reverseList(Node *p, Node *q){
    if(p!=NULL) {
        reverseList(p->next, p);
        p->next = q;
    } else {
        head = q;
    }
}

int main() {
    int arr[] = {1, 5, 12, 12, 15, 17, 17, 17, 20};

    createList(arr, 9);
    displayList(head);
    reverseList(head, NULL);
    displayList(head);

    return 0;
}
