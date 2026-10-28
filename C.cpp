#include <bits/stdc++.h>
using namespace std;

struct edge{
    int max_depth;
    int x;
    int y;
    int i;
    int j;
};

class compare{
    public:
    bool operator()(struct edge a, struct edge b){
        return a.max_depth<b.max_depth;
    }
};

edge makeEdge(int a, int b, int c, int d, int e){
    edge n;
    n.max_depth = a;
    n.x = b;
    n.y = c;
    n.i = d;
    n.j = e;
    return n;
}

int main(){
    int n;
    cin >> n;
    int depth[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin >> depth[i][j];
        }
    }
    double dist[n][n] = {10000000000000};
    dist[0][0] = 0;
    priority_queue<edge, vector<edge>, compare> pq;
    edge e = makeEdge(depth[0][1], 0, 0, 0, 1);
    edge e2 = makeEdge(depth[1][0], 0, 0, 1, 0);
    pq.push(e);
    pq.push(e2);

    while(!pq.empty()){
        edge t = pq.top();
        pq.pop();
        if(dist[t.i][t.j] < t.max_depth){
            dist[t.i][t.j] = t.max_depth;

            if(t.i > 0){
                pq.push(makeEdge(max(depth[t.i][t.j], depth[t.i-1][t.j]), t.i, t.j, t.i-1, t.j));
            }
            if(t.i < n-1){
                pq.push(makeEdge(max(depth[t.i][t.j], depth[t.i+1][t.j]), t.i, t.j, t.i+1, t.j));
            }
            if(t.j > 0){
                pq.push(makeEdge(max(depth[t.i][t.j], depth[t.i][t.j-1]), t.i, t.j, t.i, t.j-1));
            }
            if(t.i < n-1){
                pq.push(makeEdge(max(depth[t.i][t.j], depth[t.i][t.j+1]), t.i, t.j, t.i, t.j+1));
            }
        }
    }
}