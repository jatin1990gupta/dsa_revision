#include<iostream>
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

void checkSorted(Node *p){
    int x = INT16_MIN;
    while(p!=NULL){
        if(p->data<x){
            break;
        }
        x = p->data;
        p = p->next;
    }

    if(p!=NULL){
        cout << "Unsorted";
    } else {
        cout << "Sorted";
    }

}

int main() {
    int arr[] = {1, 5, 12, 23, 45};

    createList(arr, 5);
    displayList(head);
    checkSorted(head);

    return 0;
}
