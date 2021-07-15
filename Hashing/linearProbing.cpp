#include<iostream>
using namespace std;

int hashh(int val){
    return val%10;
}

int insProbe(int A[], int key){
    int idx = hashh(key);
    int i=0;
    while(A[(idx+i)%10]!=-1){
        i++;
    }
    return (idx+i)%10;
}

int findOccupiedCount(int A[]){
    int count=0;
    for(int i=0;i<10;i++){
        if(A[i]!=-1){
            count++;
        }
    }
    return count;
}

void copyToNewArray(int A[], int B[], int key){
    for(int i=0, j=0;i<10;i++){
        if(A[i]!=-1 && A[i]!=key){
            B[j++] = A[i];
        }
    }
}

class hashList {
    public:
        int h[10];

    void insertElem(int A[], int n){
        for(int i=0;i<10;i++){
            h[i] = -1;
        }
        for(int i=0;i<n;i++){
            int idx = insProbe(h, A[i]);
            h[idx] = A[i];
        }
    }

    int searchHash(int key){
        int idx = hashh(key);
        int i=0;
        while(h[idx+i]!=-1){
            if(h[idx+i]==key){
                return idx+i;
            }
            i++;
        }
        return -1;
    }

    void deleteElem(int num){
        int nwSize = findOccupiedCount(h) - 1;
        int nwArr[nwSize];
        copyToNewArray(h, nwArr, num);
        insertElem(nwArr, nwSize);
    }

    void printList(){
        for(int i=0;i<10;i++){
            cout<<h[i]<<" ";
        }
        cout<<endl;
    }
};


void searchRes(hashList hl, int key){
    int res = hl.searchHash(key);
    if(res==-1){
        cout<<"Key Not found";
    } else {
        cout<<"Key found at index: "<<res;
    }
    cout<<endl;
}

int main() {
    hashList hl;
    int arr[] = {36, 88, 12, 37, 46};
    int n = sizeof(arr)/sizeof(arr[0]);
    hl.insertElem(arr, n);
    hl.printList();
    searchRes(hl, 12);
    hl.deleteElem(36);
    hl.printList();

    return 0;
}