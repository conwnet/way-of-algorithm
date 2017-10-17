#include <stdio.h>
#include <string.h>
#define INF 99999999

int d[110], v[110], vst[110];
int M, N, cnt, G[110][110];

int min(int a, int b)
{
    return a<b?a:b;
}

void dijkstra()
{
        int i, x;

        for(i=1; i<=N; i++) d[i] = INF;
        d[1] = 0;
        memset(vst, 0, sizeof(vst));
        while(1) {
                x = INF;
                for(i=1; i<=N; i++) {
                        if(!vst[i] && d[i]<x) x = i;
                }
                if(x==INF) break;
                vst[x] = 1;
                for(i=1; i<=N; i++) {
			if(G[x][i]<INF)
                        d[i] = min(d[i], d[x]+G[x][i]);
                }
        }
}

int main()
{
	int i, j, L, l, X, T, V, ans;

	scanf("%d%d", &M, &N);
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			G[i][j] = INF;
	scanf("%d%d%d", &v[1], &L, &X);
	for(i=0; i<X; i++) {
		scanf("%d%d", &T, &V);
		G[1][T] = V;
	}
	for(i=2; i<=N; i++) {
		scanf("%d%d%d", &v[i], &l, &X);
		if(l<L-M || l>L+M) {
			v[i] = INF;
			while(X--) scanf("%d%d", &T, &V);
		} else {
			while(X--) {
				scanf("%d%d", &T, &V);
				G[i][T] = V;
			}
		}
	}
	dijkstra();
	ans = v[1];
	for(i=2; i<=N; i++)
		ans = min(ans, d[i]+v[i]);
	printf("%d\n", ans);

	return 0;
}
