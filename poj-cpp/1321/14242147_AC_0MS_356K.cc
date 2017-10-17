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
                        getchar();
                        for(j=0; j<N; j++) {
                                scanf("%c", &c);
                                if(c=='.') maps[i][j] = 1;
                                else maps[i][j] = 0;
                        }
                }
                memset(vst, 0, sizeof(vst));
                ans = 0;

                int n, cnt;
                for(int y=(1<<M)-1; y<(1<<N); y++) {
                        for(n=y, cnt=0; n; n>>=1) cnt += 1&n;
                        if(cnt!=M) continue;
                        ///printf("---%d\n", y);
                        dfs(y, M);
                }
                printf("%d\n", ans);
        }

        return 0;
}

void dfs(int y, int n)
{
        int i;
        if(n==0) {
                ans++;
                return ;
        }
        for(i=0; i<N; i++)
                if((1<<i)&y) break;
        if(i==N) return ;
        for(int x=0; x<N; x++)
                if(!vst[x] && !maps[i][x]) {
                        vst[x] = 1;
                        dfs(y-(1<<i), n-1);
                        vst[x] = 0;
                }
}

