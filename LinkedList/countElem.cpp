#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, i;

    struct Node *head=NULL;
    struct Node *t, *last;

    cout << "Enter num of terms: ";
    cin >> n;

    head = new Node;

    cout << "Enter val";
    cin >> head->data;

    head->next = NULL;

    last = head;

    for (i = 1; i < n;i++){
        t = new Node;
        cout << "Enter val";
        cin >> t->data;
        t->next = NULL;
        last->next = t;
        last = last->next;
    }

    last = head;

    while(last!=NULL){
        cout << last->data << " ";
        last = last->next;
    }

    return 0;
}