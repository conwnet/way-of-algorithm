#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 31000;

struct SCORE {
        int n;
        int num;
};
SCORE str[100];
str[1] = str[2];
str[0].n =

struct Edge {
        int from, to, dist;
        Edge(int u, int v, int d):from(u), to(v), dist(d) {}
};

struct HeapNode {
        int d, u;
        bool operator < (const HeapNode& rhs) const {
                return d > rhs.d;
        }
};

struct Dijkstra {
        int n, m;
        vector<Edge> edges;
        vector<int> G[maxn];
        bool done[maxn];
        int d[maxn];

        void init(int n)
        {
                this->n = n;
                for(int i=0; i<n; i++) G[i].clear();
                edges.clear();
        }

        void AddEdge(int from, int to, int dist) {
                edges.push_back(Edge(from, to, dist));
                m = edges.size();
                G[from].push_back(m-1);
        }


        void dijkstra(int s)
        {
                priority_queue<HeapNode> Q;
                for(int i=0; i<n; i++) d[i] = 99999999;
                d[s] = 0;
                memset(done, 0, sizeof(done));
                Q.push((HeapNode){0, s});
                while(!Q.empty()) {
                        HeapNode x = Q.top(); Q.pop();
                        int u = x.u;
                        if(done[u]) continue;
                        done[u] = true;
                        for(int i=0; i<G[u].size(); i++) {
                                Edge& e = edges[G[u][i]];
                                if(d[e.to]>d[u]+e.dist) {
                                        d[e.to] = d[u]+e.dist;
                                        Q.push((HeapNode){d[e.to], e.to});
                                }
                        }
                }
        }
};

Dijkstra dij;
int N, M;

int main()
{
    int a, b, c;

    while(~scanf("%d%d", &N, &M)) {
            dij.init(N);
            for(int i=0; i<M; i++) {
                scanf("%d%d%d", &a, &b, &c);
                dij.AddEdge(a-1, b-1, c);

            }
            dij.dijkstra(0);
            printf("%d\n", dij.d[N-1]);
    }
    return 0;
}