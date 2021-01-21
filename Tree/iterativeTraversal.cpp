#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int data;
        TreeNode *lchild;
        TreeNode *rchild;
        TreeNode(){
            this->lchild = NULL;
            this->rchild = NULL;
        }
        TreeNode(int val){
            this->data = val;
            this->lchild = NULL;
            this->rchild = NULL;
        }
};

class Tree{
    private:
        TreeNode *root;
    public:
        Tree(){
            root = new TreeNode;
        }
        void create();
        void Preorder();
        void Inorder();
        void Levelorder();
};

void Tree::create(){
    queue<TreeNode *> Q;
    TreeNode *p, *q;
    int lval, rval;
    cout << "Enter root node value: ";
    cin >> root->data;
    Q.emplace(root);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        cout << "Enter lchild of " << p->data << ": ";
        cin >> lval;
        if(lval!=-1){
            p->lchild = new TreeNode(lval);
            Q.emplace(p->lchild);
        }

        cout << "Enter rchild of " << p->data << ": ";
        cin >> rval;
        if(rval!=-1){
            p->rchild = new TreeNode(rval);
            Q.emplace(p->rchild);
        }
    }
}

void Tree::Preorder(){
    cout << "Preorder: ";
    stack<TreeNode *> S;
    TreeNode *p = root;
    while(p || !S.empty()){
        if(p){
            cout << p->data << " ";
            S.push(p);
            p = p->lchild;
        } else {
            p = S.top();
            S.pop();
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::Inorder(){
    cout << "Inorder: ";
    stack<TreeNode *> S;
    TreeNode *p = root;
    while(p || !S.empty()){
        if(p){
            S.push(p);
            p = p->lchild;
        }
        else {
            p = S.top();
            S.pop();
            cout << p->data << " ";
            p = p->rchild;
        }
    }
    cout << endl;
}

void Tree::Levelorder(){
    cout << "Level Oder: ";
    queue<TreeNode *> Q;
    TreeNode *p;
    Q.emplace(root);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        cout << p->data << " ";
        if(p->lchild){
            Q.emplace(p->lchild);
        }
        if(p->rchild){
            Q.emplace(p->rchild);
        }
    }
    cout << endl;
}

int main() {
    Tree t;
    t.create();
    t.Preorder();
    t.Inorder();
    t.Levelorder();
    return 0;
}