#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
        int y, x;
        Point(int a, int b) {
                y = a;
                x = b;
        }
        Point(){}
};

int maps[30][30], M, N, arr[30][30], ans;

void dfs(int y, int x, int n);
void print(int y, int x)
{
        for(int i=1; i<=M; i++) {
                for(int j=1; j<=N; j++)
                        if(i==y && j==x) printf("* ");
                        else printf("%d ", maps[i][j]);
                printf("\n");
        }
        printf("\n");
}
int main()
{
        int i, j, y, x;

        while(scanf("%d%d", &N, &M)) {
                if(N==0 && M==0) break;
                memset(maps, 0, sizeof(maps));
                memset(arr, 0, sizeof(arr));
                for(i=1; i<=M; i++) {
                        for(j=1; j<=N; j++) {
                                scanf("%d", &maps[i][j]);
                                if(maps[i][j]==2) {y = i; x = j;}
                        }
                }
                ans = 9999;
                dfs(y, x, 0);
                if(ans>10) ans = -1;
                printf("%d\n", ans);

        }

        return 0;
}

void dfs(int y, int x, int n)
{
        int ty, tx, ok;

        if(0) {

        } else {
                ty = y; tx = x; ok = 0;
                while(maps[ty-1][tx]!=1) {
                        ty--;
                        if(ty<1) break;
                        if(maps[ty][tx]==3) {ans = min(ans, n+1); return;}
                        if(maps[ty-1][tx]==1) {
                                maps[ty-1][tx] = 0;
                                ok = 1;
                                break;
                        }
                }
                if(ok) {
                     //   print(ty, tx);
                        dfs(ty, tx, n+1);
                        maps[ty-1][tx] = 1;
                }

                ty = y; tx = x; ok = 0;
                while(maps[ty+1][tx]!=1) {
                        ty++;
                        if(ty>M) break;
                        if(maps[ty][tx]==3) {ans = min(ans, n+1); return;}
                        if(maps[ty+1][tx]==1) {
                                maps[ty+1][tx] = 0;
                                ok = 1;
                                break;
                        }
                }
                if(ok) {
                      //  print(ty, tx);
                        dfs(ty, tx, n+1);
                        maps[ty+1][tx] = 1;
                }

                ty = y; tx = x; ok = 0;
                while(maps[ty][tx-1]!=1) {
                        tx--;
                        if(tx<1) break;
                        if(maps[ty][tx]==3) {ans = min(ans, n+1); return;}
                        if(maps[ty][tx-1]==1) {
                                maps[ty][tx-1] = 0;
                                ok = 1;
                                break;
                        }
                }
                if(ok) {
                 //       print(ty, tx);
                        dfs(ty, tx, n+1);
                        maps[ty][tx-1] = 1;
                }

                ty = y; tx = x; ok = 0;
                while(maps[ty][tx+1]!=1) {
                        tx++;
                        if(tx>N) break;
                        if(maps[ty][tx]==3) {ans = min(ans, n+1); return;}
                        if(maps[ty][tx+1]==1) {
                                maps[ty][tx+1] = 0;
                                ok = 1;
                                break;
                        }
                }
                if(ok) {
                 //       print(ty, tx);
                        dfs(ty, tx, n+1);
                        maps[ty][tx+1] = 1;
                }
        }

}
