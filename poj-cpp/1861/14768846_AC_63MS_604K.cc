#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 15005;

struct Edge {
        int u, v, w;
}edge[maxn];
int r[maxn], p[1024], N, M, en[maxn], cnt;

int cmp(int a, int b)
{
        return edge[a].w < edge[b].w;
}

int findp(int x)
{
        return x==p[x] ? x : p[x]=findp(p[x]);
}

int kruskal()
{
        for(int i=0; i<M; i++) r[i] = i;
        for(int i=0; i<N; i++) p[i] = i;
        sort(r, r+M, cmp);
        int ret = 0;
        cnt = 0;
        for(int i=0; i<M; i++) {
                int t = r[i];
                int x = findp(edge[t].u);
                int y = findp(edge[t].v);
                if(x!=y) {
                        p[x] = y;
                        ret = max(ret, edge[t].w);
                        en[cnt++] = t;
                }
        }
        return ret;
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++)
                scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        printf("%d\n", kruskal());
        printf("%d\n", cnt);
        for(int i=0; i<cnt; i++)
                printf("%d %d\n", edge[en[i]].u, edge[en[i]].v);

        return 0;
}
