#include<iostream>
#include "Queue.h"
using namespace std;

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

        void Levelorder();

        void Height() { cout<<"Height of the tree is: "<<Height(root)<<endl; }
        int Height(TreeNode *p);
};


void Tree::createTree(){
    TreeNode *p, *q;
    Queue Q;
    int lval, rval;
    cout << "Enter root node value: ";
    cin >> root->data;
    Q.enqueue(root);
    while(!Q.empty()){
        p = Q.dequeue();
        cout << "Enter left child of "<<p->data<<": ";
        cin >> lval;
        if(lval!=-1){
            q = new TreeNode(lval);
            p->left = q;
            Q.enqueue(q);
        }
        cout << "Enter right child of "<<p->data<<": ";
        cin >> rval;
        if(rval!=-1){
            q = new TreeNode(rval);
            p->right = q;
            Q.enqueue(q);
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

void Tree::Levelorder(){
    TreeNode *p;
    Queue Q;
    Q.enqueue(root);
    cout << "Levelorder: ";
    while(!Q.empty()){
        p = Q.dequeue();
        cout << p->data << " ";
        if(p->left){
            Q.enqueue(p->left);
        }
        if(p->right){
            Q.enqueue(p->right);
        }
    }
}

int Tree::Height(TreeNode *p){
    if(!p){
        return 0;
    }
    int x=0, y=0;
    x = Height(p->left);
    y = Height(p->right);
    if(x>y){
        return x + 1;
    }
    return y + 1;
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
    t.Levelorder();
    cout << endl;
    t.Height();
    return 0;
}
