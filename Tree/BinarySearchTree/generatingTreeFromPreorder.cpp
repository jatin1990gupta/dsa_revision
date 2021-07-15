#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *lchild;
        Node *rchild;
        Node(){
            lchild = rchild = NULL;
        }
        Node(int data){
            this->data = data;
            lchild = rchild = NULL;
        }
};

Node * createPre(int pre[], int n){
    stack<Node *> stk;
    Node *p, *q;
    int i = 0;
    Node *root;
    root = new Node(pre[i++]);
    p = root;
    while(i<n){
        if(pre[i]<p->data){
            q = new Node(pre[i++]);
            p->lchild = q;
            stk.push(p);
            p = q;
        } else {
            if(pre[i]>p->data && (stk.empty() || pre[i]<stk.top()->data)){
                q = new Node(pre[i++]);
                p->rchild = q;
                p = q;
            } else {
                p = stk.top();
                stk.pop();
            }
        }
    }
    return root;
}

void inOrder(Node * p){
    if(p){
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

int main() {
    int p[] = {30, 20, 10, 15, 25, 40, 50, 45};
    Node *root = createPre(p, 8);
    inOrder(root);
    return 0;
}