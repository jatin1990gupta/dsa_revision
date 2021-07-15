#include<iostream>
#include<string.h>
using namespace std;

class Node {
    public:
        char data;
        Node *next;
        Node(char data){
            this->data = data;
            next = NULL;
        }
};

class Stack{
    private:
        Node *top;
    public:
        Stack(){
            top = NULL;
        }
        void push(char elem);
        void pop();
        int stackTop();
        int isEmpty();
        int isFull();
        ~Stack();
};

void Stack::push(char elem){
    Node *q = new Node(elem);
    if(q){
        q->next = top;
        top = q;
    }
}

void Stack::pop(){
    Node *q;
    if(top){
        q = top;
        top = top->next;
        delete q;
    }
}

int Stack::stackTop(){
    if(top){
        return top->data;
    }
    return 0;
}

int Stack::isEmpty(){
    return top ? 0 : 1;
}

int Stack::isFull() {
    Node *q = new Node(0);
    return q ? 0 : 1;
}

Stack::~Stack(){
    Node *p;
    if(top){
        p = top;
        top = top->next;
        delete p;
    }
}

int isOperand(char s){
    if(s=='+' || s=='-' || s=='/' || s=='*'){
        return 0;
    }
    return 1;
}

int pre(char s){
    if(s=='+'||s=='-'){
        return 1;
    }
    else if (s == '*' || s == '/') {
        return 2;
    }
    return 0;
}

char* convert(char *st){
    char *post = new char[strlen(st) + 1];
    Stack op;
    int i=0, j=0;
    while(st[i] != '\0'){
        if(isOperand(st[i])){
            post[j++] = st[i++];
        }else{
            if(op.stackTop()) {
                if(pre(st[i])>pre(op.stackTop())){
                    op.push(st[i++]);
                } else {
                    while(!op.isEmpty()){
                        post[j++] = op.stackTop();
                        op.pop();
                    }
                    op.push(st[i++]);
                }
            } else {
                op.push(st[i++]);
            }
        }
    }
    while(!op.isEmpty()){
        post[j++] = op.stackTop();
        op.pop();
    }

    post[j] = '\0';
    return post;
}

int main(){
    char *a;
    char st[] = "a+bfc-d/e";
    a = convert(st);
    for (int i = 0; a[i] != '\0';i++){
        cout << a[i];
    }
        return 0;
}