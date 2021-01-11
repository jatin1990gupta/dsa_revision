#include<iostream>
#include<math.h>
using namespace std;

class Node {
    public:
        int coeff;
        int exp;
        Node *next;
};

class Polynomial{
    private:
        Node *head;

    public:
        Polynomial(){
            head = NULL;
        }
        void createPoly();
        int evalPoly(int val);
};

void Polynomial::createPoly(){
    int n;
    cout << "Enter order: ";
    cin >> n;
    n++;

    while(n--){
        int coeff;
        cout << "Enter coeff for degree " << n << ": ";
        cin >> coeff;

        Node *q = new Node;
        q->coeff = coeff;
        q->exp = n;
        q->next = NULL;
        
        if(head) {
            Node *p = head;
            while(p->next)
                p = p->next;
            p->next = q;
        } else {
            head = q;
        }
    }
}

int Polynomial::evalPoly(int val){
    Node *p = head;
    int res = 0;
    while (p){
        res += (p->coeff * (pow(val, p->exp)));
        p = p->next;
    }
    return res;
}

int main() {
    Polynomial p1;
    p1.createPoly();
    cout<<p1.evalPoly(2);
    return 0;
}