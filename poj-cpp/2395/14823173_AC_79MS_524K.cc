#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Edge {
        int u, v, w;
}edge[10005];
const int maxn = 2005;
int pa[maxn], ra[10005], N, M;

int cmp(int a, int b)
{
        return edge[a].w < edge[b].w;
}

int findp(int x)
{
        return x==pa[x] ? x : pa[x]=findp(pa[x]);
}

int kruskal()
{
        for(int i=1; i<=N; i++) pa[i] = i;
        for(int i=0; i<M; i++) ra[i] = i;
        sort(ra, ra+M, cmp);
        int cnt = 1;
        for(int i=0; i<M; i++) {
                int t = ra[i];
                int x = findp(edge[t].u);
                int y = findp(edge[t].v);
                if(x!=y) {
                        cnt++;
                        pa[x] = y;
                        if(cnt==N) return edge[t].w;
                }
        }
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++)
                scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        printf("%d\n", kruskal());

        return 0;
}

