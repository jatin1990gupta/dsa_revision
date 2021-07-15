#include<iostream>
using namespace std;

class Stack {
    private:
        int size;
        int top;
        int *s;
    public:
        Stack(){
            this->size = 10;
            this->top = -1;
            this->s = new int[this->size];
        }
        Stack(int size){
            this->top = -1;
            this->size = size;
            this->s = new int[this->size];
        }
        void display();
        void push(int elem);
        void pop();
        int peek(int index);
        int stackTop();
        int isEmpty();
        int isFull();
        ~Stack();
};

void Stack::display(){
    int i = top;
    if(i<0)
        cout << "Stack Empty.";
    else {
        while(i>=0){
            cout << s[i] << " ";
            i--;
        }
    }
    cout << endl;
}

void Stack::push(int elem){
    if(top!=size-1){
        top++;
        s[top] = elem;
    } else {
        cout << "Stack full"<<endl;
    }
}

void Stack::pop(){
    if(top==-1){
        cout << "Stack empty." << endl;
    } else {
        top--;
    }
}

int Stack::peek(int index){
    int x = -1;
    if(top-index+1<0 || index<1)
        return -1;
    return s[top - index + 1];
}

int Stack::stackTop(){
    if(top==-1)
        return 0;
    return s[top];
}

int Stack::isEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int Stack::isFull(){
    if(top==size-1){
        return 1;
    }
    return 0;
}

Stack::~Stack(){
    delete s;
}

int main() {
    Stack st(5);
    st.display();
    st.push(6);
    st.push(8);
    st.push(15);
    st.display();
    st.pop();
    st.display();
    cout<<st.peek(2)<<endl;
    cout << st.stackTop()<<endl;
    st.pop();
    st.pop();
    cout << st.isEmpty() << endl;
    st.push(6);
    st.push(4);
    st.push(6);
    st.push(2);
    st.push(5);
    cout << st.isFull() << endl;

    return 0;
}