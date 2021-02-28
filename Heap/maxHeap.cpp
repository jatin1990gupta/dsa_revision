#include<iostream>
using namespace std;

void insertHeap(int A[], int n){
    int temp, i=n;
    temp = A[n];
    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

int main() {
    int arr[8] = {0, 10, 20, 30, 25, 5, 40, 35};

    for(int i=2;i<8;i++){
        insertHeap(arr, i);
    }

    cout<<"Generated maxHeap: ";

    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}