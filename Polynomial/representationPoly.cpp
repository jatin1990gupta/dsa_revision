#include<iostream>
#include<math.h>
using namespace std;

class Term {
    public:
        int Coeff;
        int exp;
};

class Poly{
    private:
        int n;
        Term *t;

    public:
        Poly(int n) {
            this->n = n;
            t = new Term[n];
        }

        void create(){
            for (int i = 0; i < n;i++) {
                cout << "Enter Term(" << i + 1 << ") coeff, exp: ";
                cin >> t[i].Coeff >> t[i].exp;
            }
        }

        void displayPoly() {
            for (int i = 0; i < n; i++) {
                cout << "(" << t[i].Coeff << ")x^" << t[i].exp <<" ";
                if(i!=n-1) {
                    cout << " + ";
                }
            }
        }

        int evalPoly(int x) {
            int i, sum=0;
            for (i = 0; i < n; i++) {
                sum += (t[i].Coeff * pow(x, t[i].exp));

            }
            return sum;
        }
};


int main() {

    int n;

    cout << "Enter number of nonzero terms: ";
    cin >> n;

    Poly P(n);
    P.create();
    P.displayPoly();
    cout<<endl<<P.evalPoly(2);

    return 0;
}