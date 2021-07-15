#include<iostream>
using namespace std;

int findMax(int A[], int n){
    int res=0;
    for(int i=0;i<n;i++){
        if(A[i]>res){
            res = A[i];
        }
    }
    return res;
}

void countSort(int A[], int n){
    int i, j;
    int mxElem = findMax(A, n);
    int B[mxElem+1] = {0};
    for(i=0;i<n;i++){
        B[A[i]]++;
    }
    for(i=1,j=0;i<=mxElem;i++){
        while(B[i]!=0){
            A[j++] = i;
            B[i]--;
        }
    }
}

int main(){
    int a[] = {1,10, 54, 70, 4, 20, 2, 9, 9, 30};
    int n = sizeof(a)/sizeof(a[0]);
    countSort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}