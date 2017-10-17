#include <stdio.h>
#include <string.h>

int maps[128][128], N, M, K, cnt, ans;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

int dfs(int r, int c)
{
        cnt++;
        maps[r][c] = 0;
        for(int i=0; i<4; i++) {
                int y = r+dr[i];
                int x = c+dc[i];
                if(maps[y][x])
                        dfs(y, x);
        }
}

int main()
{
        int r, c;
        scanf("%d%d%d", &N, &M, &K);
        while(K--) {
                scanf("%d%d", &r, &c);
                maps[r][c] = 1;
        }
        ans = 0;
        for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                        if(maps[i][j]) {
                                cnt = 0;
                                dfs(i, j);
                                if(cnt>ans) ans = cnt;
                        }
                }
        }
        printf("%d\n", ans);

        return 0;
}
