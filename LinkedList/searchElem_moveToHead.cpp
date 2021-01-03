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

Node * searchElem(struct Node *p, int key) {
    struct Node *q=NULL;
    struct Node *first = p;
    while(p!=NULL) {
        if(p->data==key){
            q->next = p->next;
            p->next = first;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

int main() {
    int n, elem;
    struct Node *temp;

    cout << "Enter number of elem: ";
    cin >> n;

    createList(n);
    displayList(head);

    cout << "Enter Elem to search: ";
    cin >> elem;

    temp = searchElem(head, elem);
    if(temp){
        cout << "Element found: "<<temp->data<<endl;
    } else {
        cout << "Element not found."<<endl;
    }
    displayList(head);
}