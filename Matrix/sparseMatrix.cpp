#include<iostream>
using namespace std;

class Element {
    public:
        int i;
        int j;
        int x;

        Element(int i = 0, int j = 0, int x = 0) {
            this->i = i;
            this->j = j;
            this->x = x;
        }
};

class Sparse {
    private: 
        int m;
        int n;
        int num;
        Element *elem;

    public: 
        Sparse(int m, int n, int num) {
            this->m = m;
            this->n = n;
            this->num = num;
            elem = new Element[num];
        }
        void create();
        void display();
        ~Sparse() {
            delete[] elem;
        }
};

void Sparse::create(){
    int rowIndex, colIndex, val;
    cout << "Enter non-zero elements: \n ";
    for (int i = 0; i < num; i++)
        cin >> elem[i].i >> elem[i].j >> elem[i].x;
}

void Sparse::display(){
    int i, j, k = 0;
    for (i = 0; i < m;i++) {
        for (j = 0; j < n; j++){
            if(i==elem[k].i && j==elem[k].j) {
                cout << elem[k].x << " ";
                k++;
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}


int main()
{
    Sparse S(4, 5, 3);
    S.create();
    S.display();
    return 0;
}