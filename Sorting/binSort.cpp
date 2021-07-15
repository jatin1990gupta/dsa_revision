#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMax(int A[], int n){
    int res =0;
    for(int i=0;i<n;i++){
        if(A[i]>res){
            res = A[i];
        }
    }
    return res;
}

void binSort(int A[], int n){
    int i, j;
    int mxElem = findMax(A, n);
    queue<int> *B;
    B = new queue<int>[mxElem+1];

    for(i=0;i<n;i++){
        B[A[i]].push(A[i]);
    }    
    for(i=1,j=0;i<=mxElem;i++){
        while(!B[i].empty()){
           A[j++] = B[i].front();
           B[i].pop(); 
        }
    }
}

int main(){
    int arr[] = {1, 2, 2, 10, 3, 40, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    binSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}