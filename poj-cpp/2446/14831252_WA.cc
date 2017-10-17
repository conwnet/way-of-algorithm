#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1524;
const int INF = 0x3f3f3f3f;

struct Edge {
        int to, cap, next;
};

Edge edge[maxn*50];
int level[maxn], iter[maxn];
int fir[maxn], ec;

void add_edge(int u, int v, int w)
{
        edge[ec].to = v; edge[ec].cap = w;
        edge[ec].next = fir[u]; fir[u] = ec++;
        edge[ec].to = u; edge[ec].cap = 0;
        edge[ec].next = fir[v]; fir[v] = ec++;
}

void bfs(int s)
{
        memset(level, -1, sizeof(level));
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while(!que.empty()) {
                int tmp = que.front(); que.pop();
                for(int i=fir[tmp]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(e.cap>0 && level[e.to]<0) {
                                level[e.to] = level[tmp]+1;
                                que.push(e.to);
                        }
                }
        }
}

int dfs(int v, int t, int f)
{
        if(v==t) return f;
        for(int &i=iter[v]; i!=-1; i=edge[i].next) {
                Edge &e = edge[i];
                if(e.cap>0 && level[e.to]>level[v]) {
                        int d = dfs(e.to, t, min(f, e.cap));
                        if(d>0) {
                                e.cap -= d;
                                edge[i^1].cap += d;
                                return d;
                        }
                }
        }
        return 0;
}

int max_flow(int s, int t)
{
        int res = 0, f;
        while(1) {
                bfs(s);
                if(level[t]<0) return res;
                memcpy(iter, fir, sizeof(fir));
                while((f = dfs(s, t, INF)) > 0)
                        res += f;
        }
}

int N, M, K, maps[35][35];
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};

int main()
{
        int r, c;
        memset(fir, -1, sizeof(fir));
        scanf("%d%d%d", &N, &M, &K);
        int n = 1;
        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++)
                        maps[i][j] = n++;
        }
        for(int i=0; i<K; i++) {
                scanf("%d%d", &c, &r);
                maps[r-1][c-1] = 0;
        }
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        if(!maps[i][j]) continue;
                        for(int k=0; k<4; k++) {
                                int r = i+dr[k];
                                int c = j+dc[k];
                                if(r<0 || r>=N || c<0 || c>=M) continue;
                                if(!maps[r][c]) continue;
                                add_edge(maps[i][j], maps[r][c], 1);
                        }
                        if(maps[i][j]&1) add_edge(0, maps[i][j], 1);
                        else add_edge(maps[i][j], M*N+1, 1);
                }
        }
        if(N*M-K&1 || max_flow(0, M*N+1)<(N*M-K>>1)) printf("NO\n");
        else printf("YES\n");

        return 0;
}