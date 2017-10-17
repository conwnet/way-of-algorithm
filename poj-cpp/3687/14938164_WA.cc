#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 210;
vector<int> G[maxn];
int vst[maxn], ind[maxn], arr[maxn], maps[maxn][maxn], cnt, N, M;
int dfs(int u)
{
        vst[u] = 1;
        if(ind[u]>0) {
                for(int i=0; i<=N; i++) {
                        if(!maps[u][i]) continue;
                        int v = i;
                        if(vst[v]) return 0;
                        if(!dfs(v)) return 0;
                }
                for(int i=0; i<G[u].size(); i++) {
                        int v = G[u][i];
                        ind[v]--;
                }
        }
        arr[u] = ++cnt;
        return 1;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(ind, 0, sizeof(ind));
                memset(maps, 0, sizeof(maps));
                scanf("%d%d", &N, &M);
                for(int i=0; i<M; i++) {
                        scanf("%d%d", &u, &v);
                        if(maps[v][u]) continue;
                        maps[v][u] = 1;
                        G[u].push_back(v);
                        ind[v]++;
                }
                int faild = 0;
                memset(arr, 0, sizeof(arr)); cnt = 0;
                for(int i=1; i<=N; i++) {
                        if(!arr[i]) {
                                memset(vst, 0, sizeof(vst));
                                if(!dfs(i)) { faild = 1; break; }
                        }
                }
                if(faild) printf("-1\n");
                else {
                        printf("%d", arr[1]);
                        for(int i=2; i<=cnt; i++)
                                printf(" %d", arr[i]);
                        printf("\n");
                }
        }

        return 0;
}
