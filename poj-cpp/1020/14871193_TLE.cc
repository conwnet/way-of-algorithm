#include <stdio.h>
#include <string.h>

int maps[180][180], N, C, cake[20], vst[20];

int put_cake(int r, int c, int s)
{
        if(r+s>N || c+s>N) return 0;
        for(int i=0; i<s; i++) {
                for(int j=0; j<s; j++) {
                        if(maps[r+i][c+j]==1) return 0;
                }
        }
        for(int i=0; i<s; i++) {
                for(int j=0; j<s; j++) {
                        maps[r+i][c+j] = 1;
                }
        }
        return 1;
}

void del_cake(int r, int c, int s)
{
        for(int i=0; i<s; i++) {
                for(int j=0; j<s; j++) {
                        maps[r+i][c+j] = 0;
                }
        }
}

int dfs(int r, int c)
{
        if(r==N) return 1;
        if(c==N) return dfs(r+1, 0);
        if(maps[r][c]==1) return dfs(r, c+1);
        for(int i=0; i<C; i++) {
                if(vst[i]) continue;
                if(!put_cake(r, c, cake[i])) continue;
                vst[i] = 1;
                if(dfs(r, c+cake[i])) return 1;
                vst[i] = 0;
                del_cake(r, c, cake[i]);
        }
        return 0;
}


int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &C);
                for(int i=0; i<C; i++)
                        scanf("%d", &cake[i]);
                memset(maps, 0, sizeof(maps));
                memset(vst, 0, sizeof(vst));
                if(dfs(0, 0)) printf("KHOOOOB!\n");
                else printf("HUTUTU!\n");
        }

        return 0;
}





