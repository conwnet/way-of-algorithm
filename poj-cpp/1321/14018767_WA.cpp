#include <stdio.h>
#include <string.h>

int mapp[10][10], N, cnt;

void dfs(int n);

int main()
{
        int K, i, j;
        char t;

        while(~scanf("%d%d", &N, &K)) {
                memset(mapp, 0, sizeof(mapp));
                getchar();
                for(i=0; i<N; i++) {
                        for(j=0; j<N; j++) {
                                scanf("%c", &t);
                                if(t=='#') mapp[i][j] = 1;
                        }
                        getchar();
                }
                cnt = 0;
                dfs(K);
                printf("%d\n", cnt);
        }

        return 0;
}

void dfs(int n)
{
        int i, j, k;

        if(n==0) {
                cnt++;
                return ;
        }
        for(i=0; i<N; i++) {
                for(j=0; j<N; j++) {
                        if(mapp[i][j]==0) continue;
                        else {
                                for(k=0; k<N; k++) {
                                        mapp[i][k] = mapp[k][j] = 0;
                                }
                                dfs(n-1);
                        }
                }

        }
}


