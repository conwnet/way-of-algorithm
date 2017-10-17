#include <stdio.h>
#include <string.h>

char maps[105][105];
int N, M;

int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[8] = {0, 0, 1, -1, 1, -1, 1, -1};

void dfs(int r, int c)
{
        maps[r][c] = '*';
        for(int i=0; i<8; i++) {
                int y = r+dr[i];
                int x = c+dc[i];
                if(maps[y][x]=='@')
                        dfs(y, x);
        }
}

int main()
{
        while(scanf("%d%d", &N, &M)) {
                if(!N && !M) break;
                memset(maps, 0, sizeof(maps));
                for(int i=1; i<=N; i++)
                        scanf("%s", maps[i]+1);
                int ans = 0;
                for(int i=1; i<=N; i++) {
                        for(int j=1; j<=M; j++) {
                                if('@' == maps[i][j]) {
                                        ans++;
                                        dfs(i, j);
                                }
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}
