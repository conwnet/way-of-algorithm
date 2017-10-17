#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 210;
int G[maxn][maxn], cnt, vst[maxn], V, E, pa[maxn];
int tmp[maxn], ft, mm;

int dfs(int u)
{
        int s = 1;
        tmp[ft++] = u;
        for(int i=1; i<=V; i++)
                if(G[u][i] && !vst[i]) s += dfs(i);
        return s;
}

int cmp(int a, int b)
{
        return a > b;
}

int use[maxn];

void calc()
{
        sort(tmp, tmp+ft, cmp);
        ft--;
        int v = tmp[ft];
        if(vst[v]) return ;
        int cc = dfs(v) + cnt;
        while(use[cc]) cc++;
        use[cc] = 1;
        vst[v] = cc;
        mm++;
}

vector<int> A[maxn];
int f[maxn], k[maxn];
int DFS(int u)
{
        if(f[u]) return 1;
        f[u] = k[u] = 1;
        for(int i=0; i<A[u].size(); i++)
                if(DFS(A[u][i])) return 1;
        f[u] = 0;
        return 0;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &V, &E);
                int faild = 0; cnt = 0;
                memset(vst, 0, sizeof(vst));
                memset(use, 0, sizeof(use));
                memset(f, 0, sizeof(f));
                memset(k, 0, sizeof(k));
                memset(G, 0, sizeof(G));
                for(int i=1; i<=V; i++) A[i].clear();
                for(int i=1; i<=V; i++) pa[i] = i;
                for(int i=0; i<E; i++) {
                        scanf("%d%d", &u, &v);
                        if(G[v][u]) continue;
                        G[v][u] = 1;
                        A[v].push_back(u);
                }
                for(int i=1; i<=V; i++) {
                        if(k[i]) continue;
                        memset(f, 0, sizeof(f));
                        faild = DFS(i);
                        if(faild) break;
                }
                if(faild) { printf("-1\n"); continue; }
                for(int i=1; i<=V; i++) {
                        if(vst[i]) continue;
                        ft = 0;
                        tmp[ft++] = i;
                        mm = 0;
                        while(ft) calc();
                        cnt += mm;
                }
                printf("%d", vst[1]);
                for(int i=2; i<=V; i++)
                        printf(" %d", vst[i]);
                printf("\n");
        }

        return 0;
}
