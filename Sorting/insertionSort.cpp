#include<iostream>
using namespace std;

void InsertionSort(int A[], int n){
    for(int i=1;i<n;i++){
        int j = i-1;
        int x = A[i];
        while(A[j]>x && j>=0){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

int main(){
    int arr[] = {8, 5, 7, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    InsertionSort(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}