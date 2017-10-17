#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 99999999
#define MAX_V 201

using namespace std;

struct edge {
        long long to, cap, rev;
        edge(long long t, long long c, long long r) {
                to = t; cap = c; rev = r;
        }
        edge(){}
};

vector<edge> G[MAX_V];
long long level[MAX_V];
long long iter[MAX_V];

void add_edge(long long from, long long to, long long cap)
{
        G[from].push_back(edge(to, cap, G[to].size()));
        G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(long long s)
{
        memset(level, -1, sizeof(level));
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
                long long v = que.front(); que.pop();
                for(long long i=0; i<G[v].size(); i++) {
                        edge &e = G[v][i];
                        if(e.cap>0 && level[e.to]<0) {
                                level[e.to] = level[v]+1;
                                que.push(e.to);
                        }
                }
        }
}

long long dfs(long long v, long long t, long long f)
{
        if(v==t) return f;
        for(long long &i=iter[v]; i<G[v].size(); i++) {
                edge &e = G[v][i];
                if(e.cap>0 && level[v]<level[e.to]) {
                        long long d = dfs(e.to, t, min(f, e.cap));
                        if(d>0) {
                                e.cap -= d;
                                G[e.to][e.rev].cap += d;
                                return d;
                        }
                }
        }
        return 0;
}

long long max_flow(long long s, long long t)
{
        long long flow = 0;
        for(;;) {
                bfs(s);
                if(level[t]<0) return flow;
                memset(iter, 0, sizeof(iter));
                long long f;
                while((f = dfs(s, t, INF))>0) {
                        flow += f;
                }
        }
}

long long N, M;

int main()
{
        long long i, s, t, c;

        while(~scanf("%lld%lld", &N, &M)) {
                for(i=0; i<=M; i++) G[i].clear();
                for(i=0; i<N; i++) {
                        scanf("%lld%lld%lld", &s, &t, &c);
                     // if(s>t) s^=t^=s^=t;
                        add_edge(s, t, c);
                }
                printf("%lld\n", max_flow(1, M));
        }

        return 0;
}
