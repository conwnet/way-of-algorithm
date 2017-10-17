#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 0x3f3f3f3f

using namespace std;

const int maxv = 1100;

struct Edge {
	int t, c, r, n;
	Edge(int a, int b, int c):
		t(a), c(b), r(c) {}
	Edge() {}
};

vector<Edge> G[maxv];
int iter[maxv], level[maxv];

void add_edge(int s, int t, int c)
{
	G[s].push_back(Edge(t, c, G[t].size()));
	G[t].push_back(Edge(s, 0, G[s].size()-1));
}

void bfs(int s)
{
	queue<int> que;

	memset(level, -1, sizeof(level));
	level[s] = 0;
	que.push(s);
	while(!que.empty()) {
		int v = que.front(); que.pop();
		for(int i=0; i<G[v].size(); i++) {
			Edge &e = G[v][i];
			if(e.c>0 && level[e.t]<0) {
				level[e.t] = level[v]+1;
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

int N, P;
int arr[15][55][2];

int main()
{
	int u, v, c;

	scanf("%d%d", &N, &P);
	for(int i=1; i<=P; i++) {
		scanf("%d", &c);
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j][0]);
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j][1]);
		add_edge(i*2-1, i*2, c);
	}
	for(int i=1; i<=P; i++) {
		for(int j=1; j<=P; j++) {
			if(i==j) continue;
			int faild = 0;
			for(int k=0; k<N; k++) {
				if(arr[i][k][1]!=arr[j][k][0] && arr[i][k][1]!=2 && arr[j][k][0]!=2) {
					faild = 1;
					break;
				}
			}
			if(!faild) add_edge(i*2, j*2-1, INF);
		}
	}
	for(int i=1; i<=P; i++) {
		int faild = 0;
		for(int j=0; j<N; j++) {
			if(arr[i][j][0] && arr[i][j][0]!=2) {
				faild = 1;
				break;
			}
		}
		if(!faild) add_edge(0, i*2-1, INF);
	}
	for(int i=1; i<=P; i++) {
		int faild = 0;
		for(int j=0; j<N; j++) {
			if(0==arr[i][j][1]) {
				faild = 1;
				break;
			}
		}
		if(!faild) add_edge(i*2, P*2+1, INF);
	}
	printf("%d ", max_flow(0, P*2+1));
	int cnt = 0;
	for(int i=1; i<=P; i++) {
		for(int j=0; j<G[i*2].size(); j++) {
			Edge &e = G[i*2][j];
			if(e.c==INF) continue;
			if(e.t==P*2+1) continue;
			if(e.t != i*2-1) cnt++;
		}
	}
	printf("%d\n", cnt);
	for(int i=1; i<=P; i++) {
		for(int j=0; j<G[i*2].size(); j++) {
			Edge &e = G[i*2][j];
			if(e.c==INF) continue;
			if(e.t==P*2+1) continue;
			if(e.t != i*2-1) {
				printf("%d %d %d\n", i, (e.t+1)/2, INF-e.c);
			}
		}
	}

	return 0;
}




