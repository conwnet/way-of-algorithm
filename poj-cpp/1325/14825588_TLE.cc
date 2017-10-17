#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 128;
const int INF = 0x3f3f3f3f;
struct Edge {
        int to, cap, next;
}edge[1024*2];
int fir[maxn], ec, level[maxn], iter[maxn];

void add_edge(int u, int v, int w)
{
        edge[ec].to = v; edge[ec].cap = w;
        edge[ec].next = fir[u]; fir[u] = ec++;
        edge[ec].to = u; edge[ec].cap = 0;
        edge[ec].next = fir[v]; fir[v] = ec++;
}

void bfs(int s)
{
        queue<int> que;
        memset(level, -1, sizeof(level));
        que.push(s); level[s] = 0;
        while(!que.empty()) {
                int u = que.front(); que.pop();
                for(int i=fir[u]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(e.cap>0 && level[e.to]<0) {
                                level[e.to] = level[u]+1;
                                que.push(e.to);
                        }
                }
        }
}

int dfs(int u, int t, int f)
{
        if(u==t) return f;
        for(int &i=iter[u]; i!=-1; i=edge[i].next) {
                Edge &e = edge[i];
                if(e.cap<=0 || level[e.to]<=level[u]) continue;
                int d = dfs(e.to, t, min(f, e.cap));
                if(d>0) {
                        e.cap -= d;
                        edge[i^1].cap += d;
                        return d;
                }
        }
        return 0;
}

int max_flow(int s, int t)
{
        int f, ret = 0;
        while(1) {
                bfs(s);
                if(level[t]<0) return ret;
                memcpy(iter, fir, sizeof(fir));
                while((f=dfs(s, t, INF))>0) {
                        ret += f;
                }
        }
}

int N, M, K;

int main()
{
        int n, a, b;
        while(scanf("%d", &N) && N) {
                memset(fir, -1, sizeof(fir));
                scanf("%d%d", &M, &K);
                while(K--) {
                        scanf("%d%d%d", &n, &a, &b);
                        add_edge(a, N+b, 1);
                }
                for(int i=0; i<N; i++)
                        add_edge(N+M+1, i, 1);
                for(int i=0; i<M; i++)
                        add_edge(N+i, N+M+2, 1);
                printf("%d\n", max_flow(N+M+1, N+M+2));
        }
        return 0;
}