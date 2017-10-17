#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

struct Edge {
        int to, cost, next;
};

const int maxn = 1024;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> P;

Edge edge[maxn*100];
int dis[maxn];
int fir[maxn], ec;

int dijkstra(int s, int t)
{
        priority_queue<P> pq;
        memset(dis, 0, sizeof(dis));
        dis[s] = INF;
        pq.push(P(INF, s));
        while(!pq.empty()) {
                P tmp = pq.top(); pq.pop();
                int v = tmp.second;
                if(dis[v] != tmp.first)
                        continue;
                for(int i=fir[v]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        int f = min(dis[v], e.cost);
                        if(f > dis[e.to]) {
                                dis[e.to] = f;
                                pq.push(P(f, e.to));
                        }
                }
        }
        return dis[t];
}

int main()
{
        int nT, N, M, u, v, w;

        scanf("%d", &nT);
        for(int nC=1; nC<=nT; nC++) {
                scanf("%d%d", &N, &M);
                memset(fir, -1, sizeof(fir));
                ec = 0;
                for(int i=0; i<M; i++) {
                        scanf("%d%d%d", &u, &v, &w);
                        edge[ec].to = v; edge[ec].cost = w;
                        edge[ec].next = fir[u]; fir[u] = ec++;
                        edge[ec].to = u; edge[ec].cost = w;
                        edge[ec].next = fir[v]; fir[v] = ec++;
                }
                printf("Scenario #%d:\n", nC);
                printf("%d\n\n", dijkstra(1, N));
        }

        return 0;
}



