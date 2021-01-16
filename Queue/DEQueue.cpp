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

class DEQueue{
    private:
        Node *front, *rear;
    public:
        DEQueue(){
            front = rear = NULL;
        }

        void insertFront(int elem){
            Node *q = new Node(elem);
            if(front){
                q->next = front;
                front = q;
            }
            else {
                front = rear = q;
            }
        }
        int deleteFront(){
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
        void insertLast(int elem){
            Node *q = new Node(elem);
            if(front==NULL){
                front = rear = q;
            } else {
                rear->next = q;
                rear = rear->next;
            }
        }
        int deleteLast(){
            int x = -1;
            Node *p = front;
            if(front==NULL){
                cout << "Queue is empty" << endl;
            } else {
                while(p->next!=rear){
                    p = p->next;
                }
                rear = p;
                x = p->next->data;
                delete p->next;
                p->next = NULL;
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
    DEQueue q;
    q.Display();
    q.insertLast(6);
    q.Display();
    q.insertLast(9);
    q.Display();
    q.insertFront(3);
    q.Display();
    q.deleteFront();
    q.Display();
    q.deleteLast();
    q.Display();
}