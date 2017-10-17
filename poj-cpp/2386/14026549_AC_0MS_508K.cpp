#include <stdio.h>
#include <string.h>

int N, M, arr[128][128], cnt;

void dfs(int y, int x);

int main()
{
        int i, j;
        char c;

        scanf("%d%d", &N, &M);
        getchar();
        memset(arr, 0, sizeof(arr));
        for(i=1; i<=N; i++) {
                for(j=1; j<=M; j++) {
                        c = getchar();
                        if(c=='.') arr[i][j] = 0;
                        else arr[i][j] = 1;
                }
                getchar();
        }
        for(i=1; i<=N; i++) {
                for(j=1; j<=M; j++) {
                        if(arr[i][j]==1) {
                                cnt++;
                                dfs(i, j);
                        }
                }
        }
        printf("%d\n", cnt);

        return 0;
}

void dfs(int y, int x)
{
        arr[y][x] = 0;
        if(arr[y+1][x]==1) dfs(y+1, x);
        if(arr[y-1][x]==1) dfs(y-1, x);
        if(arr[y][x+1]==1) dfs(y, x+1);
        if(arr[y][x-1]==1) dfs(y, x-1);
        if(arr[y+1][x+1]==1) dfs(y+1, x+1);
        if(arr[y-1][x-1]==1) dfs(y-1, x-1);
        if(arr[y+1][x-1]==1) dfs(y+1, x-1);
        if(arr[y-1][x+1]==1) dfs(y-1, x+1);
}
