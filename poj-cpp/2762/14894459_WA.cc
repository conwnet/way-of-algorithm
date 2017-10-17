#include <stdio.h>
#include <string.h>

int maps[1024][1024], vst[1024], N, M, d;

int dfs(int u)
{
        vst[u] = 1; d++;
        if(d==N) return 1;
        for(int i=1; i<=N; i++) {
                if(vst[i]) continue;
                if(maps[u][i] && dfs(i)) return 1;
        }
        return 0;
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(maps, 0, sizeof(maps));
                scanf("%d%d", &N, &M);
                while(M--) {
                        scanf("%d%d", &u, &v);
                        maps[u][v] = maps[v][u] = 1;
                }
                memset(vst, 0, sizeof(vst));
                d = 1;
                if(dfs(1)) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}
