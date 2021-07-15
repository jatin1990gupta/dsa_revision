#include<iostream>
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

void MergeLists(Node *p, Node *q){
    Node *third, *last;
    third = last = NULL;

    if(p->data<q->data){
        third = last = p;
        p = p->next;
        last->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }

    while (p != NULL && q != NULL)
    {
        if(p->data<q->data){
            last->next = p;
            last = last->next;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = last->next;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p!=NULL)
        last->next = p;
    else 
        last->next = q;

    first = third;
    second = q = p = NULL;
}


int main() {
    int A[] = {1, 5, 6, 9};
    int B[] = {3, 7, 10, 14};

    createFirst(A, 4);
    createSecond(B, 4);
    displayList(first);
    displayList(second);

    MergeLists(first, second);

    displayList(first);

    return 0;
}
