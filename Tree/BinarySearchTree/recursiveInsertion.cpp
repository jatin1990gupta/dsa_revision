#include<iostream>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *lchild;
        TreeNode *rchild;
        TreeNode(){
            this->lchild = NULL;
            this->rchild = NULL;
        }
        TreeNode(int data){
            this->data = data;
            this->lchild = NULL;
            this->rchild = NULL;
        }
};

class BST{
    private:
        TreeNode *root;
    public:
        BST(){
            root = new TreeNode;
        }
        void create();
        TreeNode * insert(TreeNode* p, int elem);
        void Preorder(){
            cout << "Preorder: ";
            Preorder(root);
            cout << endl;
        }
        void Preorder(TreeNode *p);
        }
};

void BST::create(){
    int elem;
    cout << "Enter root node value: ";
    cin >> root->data;
    while(1){
        cout << "Enter data to insert: ";
        cin >> elem;
        if(elem==-1){
            break;
        } else {
            root = insert(root, elem);
        }
    }
}

TreeNode * BST::insert(TreeNode *p, int elem){
    if(p==NULL){
        return new TreeNode(elem);
    }
    if(p->data>elem){
        p->lchild = insert(p->lchild, elem);
    }
    if(p->data<elem){
        p->rchild = insert(p->rchild, elem);
    }
    return p;
} 

void BST::Preorder(TreeNode *p){
    if(p){
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main() {
    BST t;
    t.create();
    t.Preorder();
    return 0;
}