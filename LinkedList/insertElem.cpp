#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *head ;

void createList(int n) {
    Node *last, *q;

    head = new Node;
    cout << "Enter val: ";
    cin >> head->data;
    head->next = NULL;
    last = head;

    for (int i = 1; i < n;i++){
        q = new Node;
        cout << "Enter val: ";
        cin >> q->data;
        q->next = last->next;
        last->next = q;
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
    int pos, val;
    Node *q;

    cout << "Enter value to insert: ";
    cin >> val;
    cout << "Insert at index: ";
    cin >> pos;

    while(pos>0 && p->next!=NULL){
        p = p->next;
        pos--;
    }
    q = new Node;
    q->data = val;

    q->next = p->next;
    p->next = q;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    createList(n);
    displayList(head);
    insertElem(head);
    displayList(head);

    return 0;
}
