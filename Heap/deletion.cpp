#include<iostream>
using namespace std;

void deleteElem(int A[], int &n) {

    int x, i, j;

    x = A[1];
    A[1] = A[n];

    i =1, j=2*i;

    while(j<n-1) {
        if(A[j+1]>A[j]) {
            j++;
        }

        if(A[j]>A[i]){
            swap(A[i], A[j]);
            i = j;
            j = 2*j;
        } else {
            break;
        }
    }
    A[n] = x;
    n--;
}

int main() {
    int size = 8;
    int n = 7;
    int heap[n] = {0, 40, 35, 30, 15, 10, 25, 5};

    for(int i=1;i<=n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    

    deleteElem(heap, n);

    for(int i=1;i<=n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;

    deleteElem(heap, n);

    for(int i=1;i<=n;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}