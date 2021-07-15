#include<iostream>
using namespace std;

void BubbleSort(int A[], int n){
    int flag;
    for(int j=n;j>0;j--){
        flag=0;
        for(int i=0;i<j-1;i++){
            if(A[i]>A[i+1]){
                flag=1;
                swap(A[i], A[i+1]);
            }   
        }
        if(flag==0) break;
    }
}

int main(){
    int arr[] = {8, 5, 4, 9, 7, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    BubbleSort(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}