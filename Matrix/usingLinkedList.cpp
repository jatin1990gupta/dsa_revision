#include<iostream>
using namespace std;

class Node {
    public:
        int col;
        int val;
        Node *next;
};

int main() {

    int m, n, t, i, j;
    cout << "Enter m: ";
    cin >> m;
    cout << "Enter n: ";
    cin >> n;

    Node *A[m];
    for (int i = 0; i < m; i++){
        A[i] = NULL;
    }

    cout << "Enter number of non-zero elements: ";
    cin >> t;

    while(t--){
        int x, y, val;
        cout<<"Enter i: ";
        cin >> x;
        cout<<"Enter j: ";
        cin >> y;
        cout<<"Enter val: ";
        cin >> val;

        if(A[x]){
            Node *p = A[x];

            Node *q = new Node;
            q->col = y;
            q->val = val;
            q->next = NULL;

            while(p->next){
                p = p->next;
            }
            p->next = q;
        } else {
            Node *q = new Node;
            q->col = y;
            q->val = val;
            q->next = NULL;
            A[x] = q;
        }
    }

    for (i = 0; i < m; i++){
        Node *p = A[i];
        for (j = 0; j < n;j++){
            if(p && p->col==j) {
                cout << p->val << " ";
                p = p->next;
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

        return 0;
}
