#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 512;
const int INF = 0x3f3f3f3f;
struct Edge {
        int to, cap, next;
} edge[maxn*maxn];
int vst[100], fir[128], ec;

void add_edge(int u, int v, int w)
{
        edge[ec] = (Edge){v, w, fir[u]}; fir[u] = ec++;
        edge[ec] = (Edge){u, 0, fir[v]}; fir[v] = ec++;
}

int dfs(int u, int to, int f)
{
        if(u==to) return f;
        vst[u] = 1;
        for(int i=fir[u]; i!=-1; i=edge[i].next) {
                Edge &e = edge[i];
                if(e.cap>0 && !vst[e.to]) {
                        int d = dfs(e.to, to, min(e.cap, f));
                        if(d>0) {
                                e.cap -= d;
                                edge[i^1].cap += d;
                                return d;
                        }
                }
        }
        return 0;
}

int max_flow(int s, int t)
{
        int res = 0, f;
        while(1) {
                memset(vst, 0, sizeof(vst));
                f = dfs(s, t, INF);
                if(!f) return res;
                res += f;
        }
}

int N;
int main()
{
        int n, a, b;
        while(~scanf("%d", &N)) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                memset(vst, 0, sizeof(vst));
                for(int i=1; i<=N; i++) {
                        add_edge(0, i, 1);
                        scanf("%d", &n);
                        while(n--) {
                                scanf("%d%d", &a, &b);
                                int u = N+a*12+b;
                                add_edge(i, u, 1);
                                if(!vst[u]) { vst[u] = 1; add_edge(u, 511, 1); }
                        }
                }
                printf("%d\n", max_flow(0, 511));
        }

        return 0;
}
