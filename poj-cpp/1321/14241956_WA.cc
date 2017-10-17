#include <stdio.h>
#include <string.h>

int maps[10][10], N, M, vst[10], ans;

void dfs(int y, int M);

int main()
{
        int i, j;
        char c;

        while(scanf("%d%d", &N, &M)){
                if(M==-1 && N==-1) break;
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                scanf("%c", &c);
                                if(c=='.') maps[i][j] = 1;
                                else maps[i][j] = 0;
                        }
                        getchar();
                }
                memset(vst, 0, sizeof(vst));
                ans = 0;
                for(int y=0; y<N; y++)
                        dfs(y, M);
                printf("%d\n", ans);
        }

        return 0;
}

void dfs(int y, int n)
{
        if(n==0) {
                ans++;
                return ;
        }
        if(y==N) return ;
        for(int i=0; i<M; i++) {
                if(!vst[i] && !maps[y][i]) {
                        vst[i] = 1;
                        dfs(y+1, n-1);
                        vst[i] = 0;
                }
        }
}

