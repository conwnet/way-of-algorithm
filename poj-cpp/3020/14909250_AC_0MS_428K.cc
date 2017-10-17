#include <stdio.h>
#include <string.h>

char maps[50][20];
int N, M, vst[1000], match[1000];
int fir[10000], to[1000000], next[1000000], ec;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int dfs(int u)
{
        vst[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i], w = match[v];
                if(w<0 || !vst[w] && dfs(w)) {
                        match[u] = v;
                        match[v] = u;
                        return 1;
                }
        }
        return 0;
}

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &M);
                for(int i=0; i<N; i++)
                        scanf("%s", maps[i]);
                ec = 0;
                int cc = 0;
                memset(fir, -1, sizeof(fir));
                for(int i=0; i<N; i++) {
                        for(int j=0; j<M; j++) {
                                if(maps[i][j]!='*') continue;
                                cc++;
                                for(int k=0; k<4; k++) {
                                        int y = i+dr[k];
                                        int x = j+dc[k];
                                        if(y<0 || y>=N || x<0 || x>=M) continue;
                                        if(maps[y][x]!='*') continue;
                                        to[ec] = y*M+x; next[ec] = fir[i*M+j];
                                        fir[i*M+j] = ec++;
                                        //printf("%d %d\n", i*M+j, y*M+x);
                                }
                        }
                }
                int ans = 0;
                memset(match, -1, sizeof(match));
                for(int i=0; i<N*M; i++) {
                        if(match[i]<0 && fir[i]!=-1) {
                                memset(vst, 0, sizeof(vst));
                                if(dfs(i)) ans++;
                        }
                }
                printf("%d\n", cc-ans);
        }

        return 0;
}
