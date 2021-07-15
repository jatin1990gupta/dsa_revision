#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node() {
            next = NULL;
        }

        Node(int val){
            this->data = val;
            this->next = NULL;
        }
};

class HashedList {
    public:
        Node **h;

        HashedList() {
            h = new Node*[10];
            for(int i=0;i<10;i++){
                h[i] = NULL;
            }
        }

        int hashedFunction (int val) {
            return val%10;
        }

        void insertIntoHash (int A[], int n){
            for(int i=0;i<n;i++){
                int idx = hashedFunction(A[i]);
                Node *temp = h[idx];
                if(!temp){
                    h[idx]=new Node(A[i]);
                }
                else {
                    while(temp->next && temp->next->data<A[i]){
                        temp = temp->next;
                    }
                    Node *q = new Node(A[i]);
                    if(!temp->next){
                        temp = q;
                    } else {
                        q->next = temp->next;
                        temp->next = q;
                    }
                }
            }
        }

        int searchHash(int val){
            int idx = hashedFunction(val);
            Node *temp = h[idx];
            while(temp){
                if(temp->data==val)
                    return val;
            }
            return -1;
        }
};

int main(){
    HashedList hl;
    int arr[] = {25, 30, 12, 67, 94};
    int n = sizeof(arr)/sizeof(arr[0]);
    hl.insertIntoHash(arr, n);
    cout<<hl.searchHash(30)<<endl;
    cout<<hl.searchHash(12)<<endl;
    cout<<hl.searchHash(68)<<endl;
    return 0;
}