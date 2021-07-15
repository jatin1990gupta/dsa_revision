#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        int height;
        Node *lchild;
        Node *rchild;
        Node(){
            this->lchild = this->rchild = NULL;
        }
        Node(int data){
            this->data = data;
            this->lchild = this->rchild = NULL;
        }
};

class AVL{
    private:
        Node *root;
    public:
        AVL(){
            root = NULL;
        }
        void create();
        Node *insert(Node *p, int elem);
        int NodeHeight(Node *p);
        int balFac(Node *p);
        void preOrder(Node *p);
        void preOrder(){
            preOrder(root);
        }

        Node *LLRotation(Node *p);
        Node *LRRotation(Node *p);
        Node *RRRotation(Node *p);
        Node *RLRotation(Node *p);
};

void AVL::create(){
    int val;
    cout << "Enter node value: ";
    cin >> val;
    root = insert(root, val);
    insert(root, 20);
    insert(root, 30);
    insert(root, 25);
    insert(root, 28);
    insert(root, 27);
    insert(root, 5);
}

Node * AVL::insert(Node *p, int elem){
    if(p==NULL) {
        Node *q = new Node(elem);
        q->height = 1;
        return q;
    }
    if(p->data>elem){
        p->lchild = insert(p->lchild, elem);
    } else if(p->data<elem){
        p->rchild = insert(p->rchild, elem);
    }
    p->height = NodeHeight(p);

    if(balFac(p)==2 && balFac(p->lchild)==1){
        return LLRotation(p);
    } else if(balFac(p)==2 && balFac(p->lchild)==-1){
        return LRRotation(p);
    } else if(balFac(p)==-2 && balFac(p->rchild)==1){
        return RLRotation(p);
    } else if(balFac(p)==-2 && balFac(p->rchild)==-1){
        return RRRotation(p);
    }
    return p;
}

int AVL::NodeHeight(Node *p){
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl>hr ? hl+1 : hr+1;
}

int AVL::balFac(Node *p){
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

Node * AVL::LLRotation(Node *p){
    Node *q = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    if(p==root){
        root = q;
    }
    return q;
}
Node * AVL::LRRotation(Node *p){
    Node *q = p->lchild->rchild;
    p->lchild->rchild = q->lchild;
    q->lchild = p->lchild;
    p->lchild = q->rchild;
    q->rchild = p;

    q->lchild->height = NodeHeight(q->lchild);
    q->rchild->height = NodeHeight(q->rchild);
    q->height = NodeHeight(q);
    
    if(p==root){
        root = q;
    }
    return q;
}

Node * AVL::RLRotation(Node *p){
    Node *q = p->rchild->lchild;
    p->rchild->lchild = q->rchild;
    q->rchild = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;

    q->lchild->height = NodeHeight(q->lchild);
    q->rchild->height = NodeHeight(q->rchild);
    q->height = NodeHeight(q);

    if(p==root){
        root = q;
    }
    return q;
}

Node * AVL::RRRotation(Node *p){
    Node *q = p->rchild;
    p->rchild = q->lchild;
    q->lchild = p;

    p->height = NodeHeight(p);
    q->height = NodeHeight(q);

    if(p==root){
        root = q;
    }
    return q;
}

void AVL::preOrder(Node *root){
    if(root){
        cout << root->data << " ";
        preOrder(root->lchild);
        preOrder(root->rchild);
    }
}

int main(){
    AVL t;
    t.create();
    t.preOrder();
    return 0;
}