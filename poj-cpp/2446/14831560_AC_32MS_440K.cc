#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 1524;
const int INF = 0x3f3f3f3f;

struct Edge {
        int to, cap, next;
};

Edge edge[maxn*50];
int vst[maxn];
int fir[maxn], ec;

void add_edge(int u, int v, int w)
{
        edge[ec].to = v; edge[ec].cap = w;
        edge[ec].next = fir[u]; fir[u] = ec++;
        edge[ec].to = u; edge[ec].cap = 0;
        edge[ec].next = fir[v]; fir[v] = ec++;
}

int dfs(int v, int t, int f)
{
        if(v==t) return f;
        vst[v] = 1;
        for(int i=fir[v]; i!=-1; i=edge[i].next) {
                Edge &e = edge[i];
                if(!vst[e.to] && e.cap>0) {
                        int d = dfs(e.to, t, min(f, e.cap));
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
                if(f==0) return res;
                res += f;
        }
}

int N, M, K, maps[35][35];
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, 1, -1, 0};

int main()
{
        int r, c;
        memset(fir, -1, sizeof(fir));
        scanf("%d%d%d", &N, &M, &K);
        int n = 1;
        for(int i=0; i<N; i++) {
                if(!(M&1)) n++;
                for(int j=0; j<M; j++) {
                      //  printf("%3d", n);
                        maps[i][j] = n++;
                }
            //    printf("\n");
        }
        for(int i=0; i<K; i++) {
                scanf("%d%d", &c, &r);
                maps[r-1][c-1] = 0;
        }
        int cnt = 0;
        for(int i=0; i<N; i++) {
                for(int j=0; j<M; j++) {
                        if(!maps[i][j]) continue;
                        for(int k=0; k<4; k++) {
                                if(!(maps[i][j]&1)) continue;
                                int r = i+dr[k];
                                int c = j+dc[k];
                                if(r<0 || r>=N || c<0 || c>=M) continue;
                                if(!maps[r][c]) continue;
                                add_edge(maps[i][j], maps[r][c], 1);
                        }
                        if(maps[i][j]&1) add_edge(0, maps[i][j], 1);
                        else add_edge(maps[i][j], n, 1);
                }
        }
        //printf("-- %d\n", max_flow(0, n));
        if(N*M-K&1 || max_flow(0, n)!=(N*M-K)>>1) printf("NO\n");
        else printf("YES\n");

        return 0;
}
