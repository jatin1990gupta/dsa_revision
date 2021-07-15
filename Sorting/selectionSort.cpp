#include<iostream>
using namespace std;

void SelectionSort(int A[], int n){
    for(int i=0;i<n-1;i++){
        int k, j;
        k=i, j = i+1;
        while(j<n){
            if(A[j]<A[k]){
                k=j;
            }
            j++;
        }
        swap(A[i], A[k]);
    }
}

int main(){
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    SelectionSort(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}