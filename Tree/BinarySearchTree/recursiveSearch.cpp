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
        void insert(int elem);
        void Preorder(){
            cout << "Preorder: ";
            Preorder(root);
            cout << endl;
        }
        void Preorder(TreeNode *p);
        
        TreeNode* RSearch(TreeNode*p, int elem);

        TreeNode* RSearch(int elem){
            return RSearch(root, elem);
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
            insert(elem);
        }
    }
}

void BST::insert(int elem){
    TreeNode *p = root;
    TreeNode *q = NULL;
    TreeNode *r = new TreeNode(elem);
    while(p){
        q = p;
        if(elem==p->data)
            return;
        else if(p->data>elem)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if(q){
        p = q;
    }
    if(elem>p->data)
        p->rchild = r;
    else
        p->lchild = r;
} 

void BST::Preorder(TreeNode *p){
    if(p){
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

TreeNode* BST::RSearch(TreeNode* p, int elem){
    if(p){
        if(p->data==elem)
            return p;
        else if(p->data>elem)
            return RSearch(p->lchild, elem);
        else
            return RSearch(p->rchild, elem);
    }
    return NULL;
}

int main() {
    BST t;
    t.create();
    t.Preorder();
    int elem = 20;
    if(t.RSearch(elem)){
        cout << "Element found by Recursion...! " << elem << endl;
    } else {
        cout << "Elem not found!"<<endl;
    }
    return 0;
}