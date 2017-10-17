#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 99999999
#define min(x,y) (x)<(y)?(x):(y)

int d[110], v[110], vst[110], prev[110];
int M, N, cnt, G[110][110], lim[110];

void dijkstra()
{
        int i, j, x;
	
	//for(i=1; i<=N; i++) { for(int j=1; j<=N; j++) printf("%10d", G[i][j]); printf("\n"); }
	//for(i=1; i<=N; i++) printf("%d--", lim[i]);
        for(i=1; i<=N; i++) d[i] = INF;
        d[1] = 0;
        memset(vst, 0, sizeof(vst));
	memset(prev, -1, sizeof(prev));
        while(1) {
                x = INF;
                for(i=1; i<=N; i++) {
                        if(!vst[i] && d[i]<x) x = i;
                }
                if(x==INF) break;
                vst[x] = 1;
                for(i=1; i<=N; i++) {
			for(j=x; j!=-1; j=prev[j])
				if(abs(lim[i]-lim[j])>M) break;
			//printf("\n j = %d--------\n", j);
			if(j!=-1) continue;
			if(d[x]+G[x][i]<d[i]) {
				d[i] = d[x]+G[x][i];
				prev[i] = x;
			}
                }
        }
}

int main()
{
	int i, j, X, T, V, ans;

	scanf("%d%d", &M, &N);
	for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
			G[i][j] = INF;
	scanf("%d%d%d", &v[1], &lim[1], &X);
	for(i=0; i<X; i++) {
		scanf("%d%d", &T, &V);
		G[1][T] = V;
	}
	for(i=2; i<=N; i++) {
		scanf("%d%d%d", &v[i], &lim[i], &X);
		if(lim[i]<lim[1]-M || lim[i]>lim[1]+M) {
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

