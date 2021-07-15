#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int getDigit(int num, int d){
    return (num/d)%10;
}

int findMax(int A[], int n){
    int res=0;
    for(int i=0;i<n;i++){
        if(A[i]>res){
            res = A[i];
        }
    }
    return res;
}

void radixSort(int A[], int n){
    int i, j;
    queue<int> *B;
    B = new queue<int>[10];

    int mxElem = findMax(A, n);

    int d = 1;

    while(d<mxElem){
        for(i=0;i<n;i++){
            int lDig = getDigit(A[i], d);
            B[lDig].push(A[i]);
        }

        for(i=0,j=0;i<10;i++){
            while(!B[i].empty()){
                A[j++] = B[i].front();
                B[i].pop();
            }
        }
        d*=10;
    }
}

int main(){
    int arr[] = {1, 3, 4, 4, 20, 17, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}