#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 0x3f3f3f3f

struct Edge {
        int to, cap, cost, rev;
        Edge(int a, int b, int c, int d):
                to(a), cap(b), cost(c), rev(d) {}
        Edge() {}
};

typedef pair<int, int> Pos;
const int maxv = 5010;

int V;
vector<Edge> G[maxv];
int h[maxv], dis[maxv];
int prevv[maxv], preve[maxv];

void add_edge(int from, int to, int cap, int cost)
{
        G[from].push_back(Edge(to, cap, cost, G[to].size()));
        G[to].push_back(Edge(from, 0, -cost, G[from].size()-1));
}

int min_cost_flow(int s, int t, int f)
{
        int res = 0;
        memset(h, 0, sizeof(h));
        while(f > 0) {
                priority_queue<Pos, vector<Pos>, greater<Pos> > que;
                memset(dis, 0x3f, sizeof(dis));
                dis[s] = 0;
                que.push(Pos(0, s));
                while(!que.empty()) {
                        Pos tmp = que.top();
                        que.pop();
                        int v = tmp.second;
                        if(dis[v]<tmp.first)
                                continue;
                        for(int i=0; i<G[v].size(); i++) {
                                Edge &e = G[v][i];
                                if(e.cap>0 && dis[e.to] > dis[v]+e.cost+h[v]-h[e.to]) {
                                        dis[e.to] = dis[v]+e.cost+h[v]-h[e.to];
                                        prevv[e.to] = v;
                                        preve[e.to] = i;
                                        que.push(Pos(dis[e.to], e.to));
                                }
                        }
                }
                if(dis[t]==INF) {
                        return -1;
                }
                for(int v=0; v<V; v++)
                        h[v] += dis[v];
                int d = f;
                for(int v=t; v!=s; v=prevv[v]) {
                        d = min(d, G[prevv[v]][preve[v]].cap);
                }
                f -= d;
                res += d*h[t];
                for(int v=t; v!=s; v=prevv[v]) {
                        Edge &e = G[prevv[v]][preve[v]];
                        e.cap -= d;
                        G[v][e.rev].cap += d;
                }
        }
        return res;
}

int N, M, K, F;

int main()
{
        int u;
        while(scanf("%d%d%d", &N, &M, &K)) {
                if(!N && !M && !K) break;
                V = 2+(M+N)*K; F = 0;
                for(int i=0; i<=V; i++) G[i].clear();
                for(int i=0; i<N; i++) {
                        for(int j=0; j<K; j++) {
                                scanf("%d", &u);
                                add_edge(2+M*K+i*K+j, 1, u, 0);
                                F += u;
                        }
                }
                for(int i=0; i<M; i++) {
                        for(int j=0; j<K; j++) {
                                scanf("%d", &u);
                                add_edge(0, 2+i*K+j, u, 0);
                        }
                }
                for(int k=0; k<K; k++) {
                        for(int i=0; i<N; i++) {
                                for(int j=0; j<M; j++) {
                                        scanf("%d", &u);
                                        add_edge(2+j*K+k, 2+M*K+i*K+k, INF, u);
                                }
                        }
                }
                printf("%d\n", min_cost_flow(0, 1, F));
        }

        return 0;
}
