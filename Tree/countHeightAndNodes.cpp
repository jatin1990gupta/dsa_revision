#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left;
        TreeNode *right;
        TreeNode(){
            this->left = 0;
            this->right = 0;
        }
        TreeNode(int data){
            this->data = data;
            this->left = 0;
            this->right = 0;
        }
};

class Tree{
    public:
        TreeNode *root;
        Tree(){
            root = new TreeNode;
        }
        void createTree();

        void Preorder() {
            cout << "Preorder: ";
            Preorder(root);
            cout << endl;
        }
        void Preorder(TreeNode *p);

        int Height(TreeNode *p);
        void Height() {
            cout << "Height of tree is: "<<Height(root);
            cout << endl;
        }
        int countNodes(TreeNode *p);
        void countNodes() {
            cout << "No. of nodes are: "<<countNodes(root);
            cout << endl;
        }
};


void Tree::createTree(){
    TreeNode *p, *q;
    queue<TreeNode *> Q;
    int lval, rval;
    cout << "Enter root node value: ";
    cin >> root->data;
    Q.emplace(root);
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        cout << "Enter left child of "<<p->data<<": ";
        cin >> lval;
        if(lval!=-1){
            q = new TreeNode(lval);
            p->left = q;
            Q.emplace(q);
        }
        cout << "Enter right child of "<<p->data<<": ";
        cin >> rval;
        if(rval!=-1){
            q = new TreeNode(rval);
            p->right = q;
            Q.emplace(q);
        }
    }
}

void Tree::Preorder(TreeNode *p){
    if(p){
        cout << p->data<<" ";
        Preorder(p->left);
        Preorder(p->right);
    }
}

int Tree::Height(TreeNode *p){
    if(p) {
        int x, y;
        x = Height(p->left);
        y = Height(p->right);

        if(x>y)
            return x + 1;
        return y + 1;
    }
    return 0;
}

int Tree::countNodes(TreeNode *p){
    if(p){
        int x, y;
        x = countNodes(p->left);
        y = countNodes(p->right);
        return x + y + 1;
    }
    return 0;
}

int main() {
    Tree t;
    t.createTree();
    t.Preorder();
    t.Height();
    t.countNodes();
    return 0;
}
