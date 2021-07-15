#include<iostream>
#include<string.h>
using namespace std;

class Node {
    public:
        char data;
        Node *next;
        Node(int data){
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
        void push(int elem);
        void pop();
        int stackTop();
        int isEmpty();
        int isFull();
        ~Stack();
};

void Stack::push(int elem){
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

int isBalance(char *s){
    Stack st;
    int codeGap;
    int n = strlen(s);
    for (int i = 0; i<n ;i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[') {
            st.push(s[i]);
        } else if(s[i]==')'|| s[i]=='}' || s[i]==']'){
            if(st.isEmpty()){
                return 0;
            }
            if(st.stackTop()=='(') {
                codeGap = 1;
            } else {
                codeGap = 2;
            }
            if(st.stackTop()+codeGap==s[i])
                st.pop();
        }
    }
    if(!st.isEmpty())
        return 0;
    return 1;
}

int main(){
    char st[] = "{([a+b]*[c-d])/e}";
    cout<<isBalance(st);
    return 0;
}