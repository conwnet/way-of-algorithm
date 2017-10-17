#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1024;
const int maxe = 20005;
struct Edge {
        int u, v, c;
}edge[maxe];
int ra[maxe], pa[maxn], N, M;

int cmp(int a, int b)
{
        return edge[a].c > edge[b].c;
}

int findp(int x)
{
        return x==pa[x] ? x : pa[x]=findp(pa[x]);
}

int kruskal()
{
        int ret = 0, cnt = 0;
        for(int i=0; i<=N; i++) pa[i] = i;
        for(int i=0; i<M; i++) ra[i] = i;
        sort(ra, ra+M, cmp);
        for(int i=0; i<M; i++) {
                int t = ra[i];
                int x = findp(edge[t].u);
                int y = findp(edge[t].v);
                if(x!=y) {
                        pa[x] = y;
                        cnt++;
                        ret += edge[t].c;
                }
        }
        if(cnt<N-1) return -1;
        return ret;
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++)
                scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].c);
        printf("%d\n", kruskal());

        return 0;
}
