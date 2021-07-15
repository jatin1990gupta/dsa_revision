#include<iostream>
#include<cstring>
using namespace std;

int hash1(int key){
    return key%10;
}

int hash2(int key){
    return (7 - (key % 7));
}

int insProbe(int A[], int val){
    int i = 0;
    while(A[(hash1(val)+i*hash2(val))%10]!=-1){
        i++;
    }
    return (hash1(val) + i * hash2(val)) % 10;
}

class hashList{
    public:
        int h[10];

        hashList(){
            memset(h, -1, sizeof(h));
        }

        void insertHash(int A[], int n){
            for (int i = 0; i < n;i++){
                int idx = insProbe(h, A[i]);
                h[idx] = A[i];
            }
        }

        void printList(){
            for (int i = 0; i < 10;i++){
                cout << h[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    hashList hl;
    int arr[] = {5, 25, 15, 35, 95};
    int n = sizeof(arr) / sizeof(arr[0]);
    hl.printList();
    hl.insertHash(arr, n);
    hl.printList();
    return 0;
}