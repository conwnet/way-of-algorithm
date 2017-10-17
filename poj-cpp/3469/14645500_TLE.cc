#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int maxv = 20005;

struct Edge {
	int to, cap, rev;
	Edge(int a, int b, int c):
		to(a), cap(b), rev(c) {}
	Edge() {}
};

vector<Edge> G[maxv];

void add_edge(int u, int v, int c)
{
	G[u].push_back(Edge(v, c, G[v].size()));
	G[v].push_back(Edge(u, 0, G[u].size()-1));
}

int level[maxv];

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

int iter[maxv];

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
	int res = 0;
	while(1) {
		bfs(s);
		if(level[t]<0) return res;
		memset(iter, 0, sizeof(iter));
		int f;
		if((f=dfs(s, t, INF))>0) {
			res += f;
		}
	}
}

int N, M;

int main()
{
	int a, b, c;

	scanf("%d%d", &N, &M);
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
