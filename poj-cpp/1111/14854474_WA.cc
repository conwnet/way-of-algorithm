#include <stdio.h>
#include <string.h>

int N, M, R, C;
char maps[30][30], vst[30][30];
int dr[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dc[8] = {0, 0, -1, 1, -1, 1, 1, -1};

int ans;
void dfs(int r, int c)
{
        vst[r][c] = 1;
        for(int i=0; i<4; i++) {
                int y = r+dr[i];
                int x = c+dc[i];
                if(maps[y][x]!='X') ans++;
        }
        for(int i=0; i<8; i++) {
                int y = r+dr[i];
                int x = c+dc[i];
                if(vst[y][x] || maps[y][x]!='X') continue;
                dfs(y, x);
        }
}


int main()
{
        while(scanf("%d%d%d%d", &N, &M, &R, &C)) {
                if(!N && !M && !R && !C) break;
                for(int i=1; i<=N; i++)
                        scanf("%s", maps[i]+1);
                memset(maps, 0, sizeof(maps));
                ans = 0; memset(vst, 0, sizeof(vst));
                if(maps[R][C]=='X') dfs(R, C);
                printf("%d\n", ans);
        }

        return 0;
}





