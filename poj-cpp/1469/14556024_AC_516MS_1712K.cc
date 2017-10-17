#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int maxv = 500;

struct Edge {
	int to, cap, rev;
	Edge(int t, int c, int r):
		to(t), cap(c), rev(r) {}
	Edge() {}
};

int iter[maxv], level[maxv];
vector<Edge> G[maxv];

void add_edge(int u, int v, int f)
{
	G[u].push_back(Edge(v, f, G[v].size()));
	G[v].push_back(Edge(u, 0, G[u].size()-1));
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	que.push(s);
	level[s] = 0;
	while(!que.empty()) {
		int tmp = que.front();
		que.pop();
		for(int i=0; i<G[tmp].size(); i++) {
			Edge &e = G[tmp][i];
			if(e.cap>0 && level[e.to]<0) {
				level[e.to] = level[tmp] + 1;
				que.push(e.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if(v==t) return f;
	for(int &i=iter[v]; i<G[v].size(); i++) {
		Edge &e = G[v][i];
		if(e.cap>0 && level[e.to]>level[v]) {
			int d = dfs(e.to, t, min(f, e.cap));
			if(d>0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s, int t)
{
	int res = 0, f;
	while(1){
		bfs(s);
		if(level[t]==-1) return res;
		memset(iter, 0, sizeof(iter));
		while((f=dfs(s, t, INF))>0) {
			res += f;
		}
	}

	return 0;
}

void init()
{
	for(int i=0; i<maxv; i++)
		G[i].clear();
}

int N, P;

int main()
{
	int T, n, a;
	
	scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d%d", &P, &N);
		for(int i=1; i<=P; i++) {
			scanf("%d", &n);
			for(int j=1; j<=n; j++) {
				scanf("%d", &a);
				add_edge(i, a+P, 1);
			}
		}
		for(int i=1; i<=P; i++)
			add_edge(0, i, 1);
		for(int i=1; i<=N; i++)
			add_edge(i+P, N+P+1, 1);
		if(max_flow(0, N+P+1)==P)
			printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}




