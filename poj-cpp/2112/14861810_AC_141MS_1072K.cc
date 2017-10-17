#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1024;
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

int maps[350][350], K, C, M;

int judge(int n)
{
        ec = 0;
        memset(fir, -1, sizeof(fir));
        for(int i=1; i<=K; i++) {
                add_edge(i, K+C+1, M);
	}
	for(int i=K+1; i<=K+C; i++) {
                add_edge(0, i, 1);
	}
        for(int i=1; i<=K; i++) {
                for(int j=K+1; j<=K+C; j++) {
                        if(maps[i][j]<=n) {
                                add_edge(j, i, 1);
                        }
                }
        }
        return max_flow(0, K+C+1) >= C;
}

int main()
{
 ///       freopen("in.txt", "r", stdin);
	scanf("%d%d%d", &K, &C, &M);
	for(int i=1; i<=K+C; i++) {
		for(int j=1; j<=K+C; j++) {
			scanf("%d", &maps[i][j]);
			if(maps[i][j]==0) maps[i][j] = INF;
		}
	}
	for(int k=1; k<=K+C; k++) {
		for(int i=1; i<=K+C; i++) {
			for(int j=1; j<=K+C; j++) {
				maps[i][j] = min(maps[i][j], maps[i][k]+maps[k][j]);
			}
		}
	}
        int l = 0, r = 20000;
        while(l<r) {
                int m = (l+r)>>1;
                if(judge(m)) r = m;
                else l = m+1;
        }
        printf("%d\n", l);

 	return 0;
}
