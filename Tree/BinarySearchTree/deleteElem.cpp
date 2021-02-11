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
            root = NULL;
        }
        void create();
        TreeNode * insert(TreeNode* p, int elem);
        void Preorder(){
            cout << "Preorder: ";
            Preorder(root);
            cout << endl;
        }
        void Preorder(TreeNode *p);

        void Delete(int elem){
            Delete(root, elem);
        }
        TreeNode * Delete( TreeNode * p, int elem);
        int Height(TreeNode *p);
        TreeNode *InPre(TreeNode *p);
        TreeNode *InSucc(TreeNode *p);
};

void BST::create(){
    int elem;
    int rootVal;
    cout << "Enter root node value: ";
    cin >> rootVal;
    root = insert(root, rootVal);
    while(1){
        cout << "Enter data to insert: ";
        cin >> elem;
        if(elem==-1){
            break;
        } else {
            insert(root, elem);
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

TreeNode * BST::Delete(TreeNode *p, int elem){

    TreeNode *q;

    if(p==NULL){
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL && p->data==elem){
        if(p==root){
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(p->data>elem){
        p->lchild = Delete(p->lchild, elem);
    } else if(p->data<elem){
        p->rchild = Delete(p->rchild, elem);
    } else {
        if(Height(p->lchild)>Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int BST::Height(TreeNode *p){
    int x, y;
    if(p){
        x = Height(p->lchild);
        y = Height(p->rchild);

        if(x>y)
            return x + 1;
        return y + 1;
    }
    return 0;
}

TreeNode* BST::InPre(TreeNode *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}
TreeNode* BST::InSucc(TreeNode *p){
    while(p && p->lchild){
        p = p->lchild;
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
    t.Delete(50);
    t.Preorder();
    return 0;
}