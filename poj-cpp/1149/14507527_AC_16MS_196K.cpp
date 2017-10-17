#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
	int t, c, r;
	Edge(int a, int b, int c):
		t(a), c(b), r(c) {}
	Edge() {}
};

vector<Edge> G[110];
int level[110], iter[110];

void add_edge(int s, int t, int c)
{
	G[s].push_back(Edge(t, c, G[t].size()));
	G[t].push_back(Edge(s, 0, G[s].size()-1));
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[s] = 0;
	que.push(s);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int i=0; i<G[v].size(); i++) {
			Edge &e = G[v][i];
			if(e.c>0 && level[e.t]<0) {
				level[e.t] = level[v] + 1;
				que.push(e.t);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if(v==t) return f;
	for(int &i=iter[v]; i<G[v].size(); i++) {
		Edge &e = G[v][i];
		if(e.c>0 && level[v]<level[e.t]) {
			int d = dfs(e.t, t, min(f, e.c));
			if(d>0) {
				e.c -= d;
				G[e.t][e.r].c += d;
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
		while((f=dfs(s, t, INF)) > 0) {
			res += f;
		}
	}
}

int N, M;
int pig[1005], vst[1005], prev[1005];

int main()
{
	scanf("%d%d", &M, &N);
	for(int i=1; i<=M; i++) {
		scanf("%d", &pig[i]);
	}
	int n, p, c;
	for(int i=1; i<=N; i++) {
		scanf("%d", &n);
		for(int j=0; j<n; j++) {
			scanf("%d", &p);
			if(!vst[p]) {
				add_edge(0, i, pig[p]);
				vst[p] = 1;
				prev[p] = i;
			} else {
				add_edge(prev[p], i, INF);
				prev[p] = i;
			}
		}
		scanf("%d", &c);
		add_edge(i, N+1, c);
	}
	printf("%d\n", max_flow(0, N+1));

	return 0;
}

