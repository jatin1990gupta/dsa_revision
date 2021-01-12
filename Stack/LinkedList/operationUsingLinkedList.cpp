#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

class Stack {
    private:
        Node *top;
    public:
        Stack() {
            top = NULL;
        }
        void Display();
        void push(int elem);
        void pop();
        int peek(int index);
        int stackTop();
        int isEmpty();
        int isFull();
        ~Stack();
};

void Stack::Display() {
    Node *p = top;
    if(p){
        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    } else {
        cout << "Stack empty" << endl;
    }
}

void Stack::push(int elem){
    Node *q = new Node(elem);
    q->next = top;
    top = q;       
}

void Stack::pop(){
    Node *p = top;
    if(p){
        top = top->next;
        delete p;
    } else{
        cout << "Stack is Empty";
    }
}

int Stack::peek(int index){
    Node *p = top;
    for (int i = 0; p != NULL && i < index - 1;i++){
        p = p->next;
    }
    if(p){
        return p->data;
    }
    return -1;
}

int Stack::stackTop(){
    Node *p = top;
    if(p){
        return p->data;
    }
    return -1;
}

int Stack::isEmpty() {
    return top ? 0 : 1;
}
int Stack::isFull() {
    Node *p = new Node(0);
    return p ? 0 : 1;
}

Stack::~Stack() {
    Node *p = NULL;
    while(top){
        p = top;
        top = top->next;
        delete p;
    }
}

int main() {

    Stack st;
    st.Display();
    st.push(5);
    st.Display();
    st.push(6);
    st.Display();
    st.push(12);
    st.Display();
    st.push(8);
    st.Display();
    st.pop();
    st.Display();
    cout << "Element at pos 2: " << st.peek(2)<<endl;
    cout << "Stack top: " << st.stackTop() << endl;
    cout << "Stack is empty: " << st.isEmpty() << endl;
    cout << "Stack is full: " << st.isEmpty() << endl;

    return 0;
}