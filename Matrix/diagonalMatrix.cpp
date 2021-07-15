#include<iostream>
using namespace std;

class Diagonal{
    private:
        int n;
        int *A;

    public: 
        Diagonal(int n){
            this->n = n;
            A = new int[n];
        }
        void create();
        int get();
        void set();
        void display();
        ~Diagonal() {
            delete[] A;
        }
};

void Diagonal::create(){
    for (int i = 0; i < n;i++){
        cin >> A[i];
    };

}

int Diagonal::get(){
    int i, j;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    if(i==j)
        return A[i - 1];
    return 0;
}

void Diagonal::set(){
    int i, j, x;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    cout << "Enter val: ";
    cin >> x;
    if(i==j)
        A[i-1] = x;
}

void Diagonal::display(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==j)
                cout << A[i]<< " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, ch, i, j, x;
    cout << "Enter Dimentions: ";
    cin >> n;
    Diagonal d(n);

    do{
        cout << "1.Create" << endl;
        cout << "2.Get" << endl;
        cout << "3.Set" << endl;
        cout << "4.Display" << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        switch(ch){
            case 1:
                d.create();
                break;
            case 2:
                d.get();
                break;
            case 3:
                d.set();
                break;
            case 4:
                d.display();
                break;
            default:
                break;
        }
    } while (ch <= 4);
    return 0;
}