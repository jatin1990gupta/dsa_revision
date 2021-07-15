#include<iostream>
using namespace std;

int I = INT16_MAX;

int cost[8][8] = {{I, I, I, I, I, I, I, I},
                {I, I, 25, I, I, I, 5, I},
                {I, 25, I, 12, I, I, I, 10},
                {I, I, 12, I, 8, I, I, I},
                {I, I, I, 8, I, 16, I, 14},
                {I, I, I, I, 16, I, 20, 18},
                {I, 5, I, I, I, 20, I, I},
                {I, I, 10, I, 14, 18, I, I}};

int t[2][6] = {{0}};
int near[8] = {I, I, I, I, I, I, I, I};


int main() {
    int i, j, u, v;
    int n = 7;
    int e = n - 1;
    int min = I;

    for (i = 1; i <=n;i++){
        for (j = i; j <=n;j++){
            if(cost[i][j]<min){
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for (i = 1; i <= n;i++){
        if(near[i]!=0){
            if(cost[i][u]<cost[i][v])
                near[i] = u;
            else
                near[i] = v; 
        }
    }

    for (i = 1; i < e;i++){
        int k;
        min = I;
        for (j = 1; j <= n; j++)
        {
            if (near[j] != 0)
            {
                if (cost[j][near[j]] < min)
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n;j++){
            if(near[j] !=0){
                if(cost[j][k] < cost[j][near[j]]){
                    near[j] = k;
                }
            }
        }
    }

    cout << "Prims Minimum cost spanning tree:" << endl;
    for (j = 0; j < e;j++){
        cout << "("<<t[0][j] << ", "<<t[1][j]<<")"<<endl;
    }

    return 0;
}