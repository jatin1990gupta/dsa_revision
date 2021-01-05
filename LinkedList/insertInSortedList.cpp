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

void insertElem(Node *p){
    Node *q, *temp=NULL;
    q = new Node;
    cout << "Enter value to insert: ";
    cin>>q->data;
    q->next = NULL;

    while(p!=NULL){
        if(p->data>q->data) {
            if(temp==NULL) {
                q->next = p->next;
                p->next = q;
            } else {
                q->next = temp->next;
                temp->next = q;
            }
            break;
        }
        temp = p;
        p = p->next;
    }
}

int main() {
    int arr[] = {1, 5, 12, 23, 45};

    createList(arr, 5);
    displayList(head);
    insertElem(head);
    displayList(head);

    return 0;
}
