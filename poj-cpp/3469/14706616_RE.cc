
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 20005;
const int INF = 0x3f3f3f3f;

struct Edge {
        int to, cap, next;
};

Edge edge[maxn*20];
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
        for(int i=fir[v]; i!=-1; i=edge[i].next) {
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
                memset(iter, 0, sizeof(iter));
                while((f = dfs(s, t, INF)) > 0)
                        res += f;
        }
}

int N, M;

int main()
{
	int a, b, c;

	scanf("%d%d", &N, &M);
	memset(fir, -1, sizeof(fir));
	ec = 0;
	for(int i=1; i<=N; i++) {
		scanf("%d%d", &a, &b);
		add_edge(0, i, a);
		add_edge(i, N+1, b);
	}
	while(M--) {
		scanf("%d%d%d", &a, &b, &c);
		add_edge(a, b, c);
		add_edge(b, a, c);
	}
	printf("%d\n", max_flow(0, N+1));

	return 0;
}




