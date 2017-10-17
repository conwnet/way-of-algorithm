
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int maps[41], N, C, cake[11], ca;

int dfs(int c)
{
        int i, j, f, mi = 41;
        if(c==C) return 1;
        for(i=0; i<N; i++) {
                if(maps[i] < mi) {
                        mi = maps[i];
                        f = i;
                }
        }
        for(int i=10; i>0; i--) {
                if(!cake[i] || f+i>N || mi+i>N) continue;
                for(j=f; j<f+i; j++)
                        if(maps[j]>mi) break;
                if(j<f+i) continue;
                cake[i]--;
                for(int j=f; j<f+i; j++)
                        maps[j] += i;
                if(dfs(c+1)) return 1;
                for(int j=f; j<f+i; j++)
                        maps[j] -= i;
                cake[i]++;
        }
        return 0;

}


int ss, SS;

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                memset(cake, 0, sizeof(cake));
                scanf("%d%d", &N, &C);
                SS = N*N; ss = 0;
                for(int i=0; i<C; i++) {
                        scanf("%d", &ca);
                        ss += ca*ca;
                        cake[ca]++;
                }
                memset(maps, 0, sizeof(maps));
                if(ss==SS  && dfs(0)) printf("KHOOOOB!\n");
                else printf("HUTUTU!\n");
        }

        return 0;
}





