#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void BFS(int G[][8], int start, int n){
    bool visited[8] = {0};
    queue<int> q;

    q.push(start);
    visited[start] = 1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int i = 0; i < n;i++){
            if(G[u][i]==1 && visited[i]==0){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

void DFS(int G[][8], int start, int n){
    static bool visited[8] = {0};

    if(visited[start]==0){
        cout << start << " ";
        visited[start] = 1;
        for (int i = 1; i < n;i++){
            if(G[start][i]==1 && visited[i]==0){
                DFS(G, i, n);
            }
        }
    }
}

int main() {     
    int G[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0, 0, 1, 0},
                    {0, 1, 0, 1, 0, 0, 0, 1},
                    {0, 0, 1, 0, 1, 0, 0, 0},
                    {0, 0, 0, 1, 0, 1, 0, 1},
                    {0, 0, 0, 0, 1, 0, 1, 1},
                    {0, 1, 0, 0, 0, 1, 0, 0},
                    {0, 0, 1, 0, 1, 1, 0, 0}};

    //Breadth First Search (BFS)
    cout << "BFS: ";
    BFS(G, 7, 8);

    cout << endl;
    
    // Depth First Search (DFS)
    cout << "DFS: ";
    DFS(G, 7, 8);
    return 0;
}