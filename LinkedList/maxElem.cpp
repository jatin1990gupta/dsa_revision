#include<iostream>
#include<math.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

void createList(struct Node *last, int n) {
    int i;
    struct Node *q;

    for(i=1; i<n;i++){
        q = new Node;
        cout << "Enter val: ";
        cin >> q->data;
        q->next = last->next;
        last->next = q;
        last = last->next;
    }
}

void displayList(struct Node *last){

    while(last!=NULL) {
        cout << last->data << " ";
        last = last->next;
    }
    cout << endl;
}

int maxElem(struct Node *last){
    int max = -32768;

    while(last!=NULL){
        if(last->data>max){
            max = last->data;
        }
        last = last->next;
    }

    return max;
}

int main() {
    int n;
    struct Node *head, *last;

    cout << "Enter number of elem: ";
    cin >> n;

    head = new Node;
    cout << "Enter first elem val: ";
    cin >> head->data;
    head->next = NULL;

    createList(head, n);
    displayList(head);
    cout << "The max Elem is: " << maxElem(head) << endl;
}