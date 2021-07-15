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

class Queue{
    private:
        Node *front, *rear;
    public:
        Queue(){
            front = rear = NULL;
        }
        void enqueue(int elem){
            Node *q = new Node(elem);
            if(front==NULL){
                front = rear = q;
            } else {
                rear->next = q;
                rear = rear->next;
            }
        }
        int dequeue(){
            int x=-1;
            Node *p;
            if(front==NULL){
                cout << "Queue is empty"<<endl;
            } else {
                p = front;
                front = front->next;
                x = p->data;
                delete p;
            }
            return x;
        }
        void Display() {
            Node *p = front;
            if(p){
                while(p){
                    cout << p->data<<" ";
                    p = p->next;
                }
                cout << endl;
            } else{
                cout << "Queue Empty" << endl;
            }
        }
};

int main(){
    Queue q;
    q.Display();
    q.enqueue(6);
    q.enqueue(9);
    q.Display();
    q.dequeue();
    q.Display();
    q.dequeue();
    q.Display();
}