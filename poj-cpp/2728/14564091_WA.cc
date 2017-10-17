#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int x, y, h;
	Node(int a, int b, int c) {
		x = a;
		y = b;
		h = c;
	}
	double dis(Node B) {
		return fabs(h-B.h) / sqrt((B.y-y)*(B.y-y)+(B.x-x)*(B.x-x));
	}
	Node() {}
};

Node node[1005];

struct Edge {
	int u, v;
	double d;
	Edge(int a, int b) {
		u = a;
		v = b;
		d = node[u].dis(node[v]);
	}
	Edge() {}
};

Edge edge[1000005];
int r[1000005], p[1005];
int N, M;

int cmp(int a, int b)
{
	return edge[a].d < edge[b].d;
}

int findp(int x)
{
	return x==p[x] ? x : p[x]=findp(p[x]);
}

double kruskal()
{
	double res = 0;
	for(int i=0; i<=N; i++)
		p[i] = i;
	for(int i=0; i<=M; i++)
		r[i] = i;
	sort(r, r+M, cmp);
	for(int i=0; i<M; i++) {
		int t = r[i];
		int x = findp(edge[t].u);
		int y = findp(edge[t].v);
		if(x!=y) {
			p[x] = y;
			res += edge[t].d;
		}
	}
	return res/(N-1);
}

int main()
{
	while(scanf("%d", &N) && N) {
		for(int i=1; i<=N; i++)
			scanf("%d%d%d", &node[i].x, &node[i].y, &node[i].h);
		M = 0;
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				if(i!=j)
					edge[M++] = Edge(i, j);
			}
		}
		//printf("%d\n", edge[3].u);
		printf("%.3lf\n", kruskal());
	}

	return 0;
}


