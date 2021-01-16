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
            this->rear = this->front = -1;
            this->size = 10;
            this->arr = new int[this->size];
        }
        Queue(int size){
            this->rear = this->front = -1;
            this->size = size;
            this->arr = new int[this->size];
        }
        void enqueue(int elem){
            if(rear==size-1){
                cout << "Queue Full" << endl;
            } else {
                arr[++rear] = elem;
            }
        }
        int dequeue(){
            int x=0;
            if(rear==front) {
                cout << "Queue is Empty" << endl;
            } else {
                x = arr[++front];
                return x;
            }
            return -1;
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
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.Display();
    return 0;
}