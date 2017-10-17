#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

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

int ss, SS;

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &C);
                SS = N*N; ss = 0;
                for(int i=0; i<C; i++) {
                        scanf("%d", &cake[i]);
                        ss += cake[i]*cake[i];
                }
                sort(cake, cake+C);
                memset(maps, 0, sizeof(maps));
                memset(vst, 0, sizeof(vst));
                if(!put_cake(0, 0, cake[C-1])) {
                        printf("HUTUTU!\n");
                        continue;
                }
                vst[C-1] = 1;
                if(ss==SS  && dfs(0, cake[C-1])) printf("KHOOOOB!\n");
                else printf("HUTUTU!\n");
        }

        return 0;
}





