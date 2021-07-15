#include<iostream>
using namespace std;

void quickSort(int A[], int l, int r){
    if(l<r){
        int pivot = A[l];
        int i = l;
        int j = r;

        do{
            do{i++;} while(A[i]<=pivot);
            do{j--;} while(A[j]>pivot);

            if(i<j) swap(A[i], A[j]);
        } while(i<j);

        swap(A[l], A[j]);
        quickSort(A, l, j);
        quickSort(A, j+1, r);
    }
}

int main() {
    int arr[] = {50, 70, 90, 40, 80, 10, 30};
    quickSort(arr, 0, 7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}