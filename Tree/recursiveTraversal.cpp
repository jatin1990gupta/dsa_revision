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
        }
        void Preorder(TreeNode *p);

        void Inorder() { 
            cout << "Inorder: ";
            Inorder(root); 
        }
        void Inorder(TreeNode *p);

        void Postorder() { 
            cout << "Postorder: ";
            Postorder(root); 
        }
        void Postorder(TreeNode *p);
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
void Tree::Inorder(TreeNode *p){
    if(p){
        Inorder(p->left);
        cout << p->data<<" ";
        Inorder(p->right);
    }   
}
void Tree::Postorder(TreeNode *p){
    if(p){
        Postorder(p->left);
        Postorder(p->right);
        cout << p->data<<" ";
    }   
}

int main() {
    Tree t;
    t.createTree();
    t.Preorder();
    cout << endl;
    t.Inorder();
    cout << endl;
    t.Postorder();
    cout << endl;
    return 0;
}
