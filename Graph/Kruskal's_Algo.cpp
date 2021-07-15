#include<iostream>
using namespace std;

int I = INT16_MAX;

int edges[3][9] = {{1, 1, 2, 2, 3, 4, 4, 5, 5},
                   {2, 6, 3, 7, 4, 5, 7, 6, 7},
                   {25, 5, 12, 10, 8, 16, 14, 20, 18}};

int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};

int included[8] = {0};

void unionn(int a, int b){
    if(set[a]>set[b]){
        set[b] = set[a] + set[b];
        set[a] = b;
    } else {
        set[a] = set[a] + set[b];
        set[b] = a;
    }
}

int findd(int u){
    int x = u;
    while(set[x]>0){
        x = set[x];
    }
    return x;
}

int main() {
    int n = 7;
    int e = n - 1;
    int t[2][6];
    int u, v;
    int i=0, j;

    while (i<e){
        int k;
        int min = I;
        for (j = 0; j < 9;j++){
            if(included[j]==0 && edges[2][j]<min){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }

        if(findd(u)!=findd(v)){
            t[0][i] = u;
            t[1][i] = v;
            unionn(findd(u), findd(v));
            i++;
        }

        included[k] = 1;
    }


    cout << "Kruskal's Minimum cost spanning tree:" << endl;
    for (j = 0; j < e;j++){
        cout << "(" << t[0][j] << ", " << t[1][j] << ")" << endl;
    }

        return 0;
}