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

void removeDuplicates(Node *p){
    Node *q=NULL;
    q = p;
    p = p->next;
    
    while(p!=NULL){
        if(p->data==q->data){
            q->next = p->next;
            delete p;
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
}

int main() {
    int arr[] = {1, 5, 12, 12, 15, 17, 17, 17, 20};

    createList(arr, 9);
    displayList(head);
    removeDuplicates(head);
    displayList(head);

    return 0;
}
