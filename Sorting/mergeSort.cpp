#include<iostream>
using namespace std;

void merge(int A[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int B[100];

    while(i<=mid && j<=h){
        if(A[i]<A[j])
            B[k++]=A[i++];
         else
            B[k++]=A[j++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    for(i=l;i<=h;i++)
        A[i]=B[i];
}


void mergeSort(int A[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(A, l, mid);
        mergeSort(A, mid+1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    mergeSort(arr, 0, 10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}