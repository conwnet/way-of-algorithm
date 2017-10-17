#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 128;
const int INF = 0x3f3f3f3f;
struct Edge{
        int u, v, w;
}edge[maxn*maxn];

int fir[maxn], ra[maxn];
int pa[maxn], N, M, ec;

int cmp(int a, int b)
{
        return edge[a].w < edge[b].w;
}

int findp(int x)
{
        return x==pa[x] ? x : pa[x]=findp(pa[x]);
}

int kruskal(int r)
{
        for(int i=1; i<=N; i++) pa[i] = i;
        int cnt = 1;
        for(int i=r; i<M; i++) {
                int t = ra[i];
                int x = findp(edge[t].u);
                int y = findp(edge[t].v);
                if(x!=y) {
                        pa[x] = y;
                        cnt++;
                }
                if(cnt==N) return edge[t].w - edge[ra[r]].w;
        }

        return INF;
}

int main()
{
        int u, v, w;
        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                for(int i=0; i<M; i++)
                        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
                for(int i=0; i<M; i++) ra[i] = i;
                sort(ra, ra+M, cmp);
                int ans = INF;
                for(int i=0; i<M; i++) {
                        int t = kruskal(i);
                        if(t==INF) break;
                        if(t<ans) ans = t;
                }
                printf("%d\n", ans<INF ? ans : -1);
        }


        return 0;
}
