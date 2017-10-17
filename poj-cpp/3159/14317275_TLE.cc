#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> P;

struct Edge {
    int to, cost;
    Edge(int a, int b) {
        to = a;
        cost = b;
    }
    bool operator < (const Edge& B) const {
        return cost < B.cost;
    }
};
vector<Edge> G[31000];
int d[31000], vst[31000], N, M;

int dijkstra(int s);

int main()
{
    int a, b, c;

    while(~scanf("%d%d", &N, &M)) {
            for(int i=0; i<M; i++) {
                scanf("%d%d%d", &a, &b, &c);
                if(c>0) G[a].push_back(Edge(b, c));
                else G[b].push_back(Edge(a, -c));
            }
            printf("%d\n", dijkstra(1));
    }
    return 0;
}

int dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > pq;

    for(int i=0; i<=N; i++) d[i] = 99999999;
    memset(vst, 0, sizeof(vst));
    d[s] = 0;
    pq.push(P(0, s));
    while(!pq.empty()) {
        P t = pq.top(); pq.pop();
        int v = t.second;
        if(v==N) break;
        if(d[v]!=t.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            Edge e = G[v][i];
            if(d[e.to]>e.cost+t.first) {
                d[e.to] = e.cost+t.first;
                pq.push(P(d[e.to], e.to));
            }
        }
    }

    return d[N];
}
