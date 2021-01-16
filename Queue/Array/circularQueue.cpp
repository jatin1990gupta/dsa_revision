#include<iostream>
using namespace std;

class Queue{
    private:
        int rear;
        int front;
        int size;
        int *arr;
    public:
        Queue(){
            this->rear = this->front = 0;
            this->size = 10;
            this->arr = new int[this->size];
        }
        Queue(int size){
            this->rear = this->front = 0;
            this->size = size;
            this->arr = new int[this->size];
        }
        void enqueue(int elem){
            if((rear+1)%size==front){
                cout << "Queue Full" << endl;
            } else {
                rear = (rear + 1) % size;
                arr[rear] = elem;
            }
        }
        int dequeue(){
            int x=-1;
            if(rear==front) {
                cout << "Queue is Empty" << endl;
            } else {
                front = (front + 1) % size;
                x = arr[front];
            }
            return x;
        }
        int queueTop() {
            if(rear!=front){
                return arr[rear];
            }
            return -1;  
        }
        void Display(){
            for (int i = front + 1; i <=rear;i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q(4);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(30);
    q.Display();
    q.dequeue();
    q.Display();
    return 0;
}