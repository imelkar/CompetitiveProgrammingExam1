#include <bits/stdc++.h>
using namespace std;

struct edge{
    int max_depth;
    int x;
    int y;
    int i;
    int j;
};


int main(){
    int n;
    cin >> n;
    int depth[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> depth[i][j];
        }
    }
    double dist[n][n] = {0};
    dist[0][0] = 0;
}