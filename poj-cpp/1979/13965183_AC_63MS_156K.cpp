#include <stdio.h>

char maps[30][30];
int H, W, cnt;

void dfs(int y, int x);

int main()
{
        int x, y, i, j;

        while(~scanf("%d%d", &W, &H)){
                getchar();
                if(H==0 && W==0) break;
                for(i=0; i<H; i++){
                        for(j=0; j<W; j++){
                                scanf("%c", &maps[i][j]);
                                if(maps[i][j]=='@'){
                                        y = i;
                                        x = j;
                                }
                        }
                        getchar();
                }
                cnt = 0;
                dfs(y, x);

                printf("%d\n", cnt);

        }

        return 0;
}


void dfs(int y, int x)
{
        maps[y][x] = '#';
        cnt++;
        if(y>0 && maps[y-1][x]=='.'){
                dfs(y-1, x);
        }
        if(y<H-1 && maps[y+1][x]=='.'){
                dfs(y+1, x);
        }
        if(x>0 && maps[y][x-1]=='.'){
                dfs(y, x-1);
        }
        if(x<W-1 && maps[y][x+1]=='.'){
                dfs(y, x+1);
        }
}
