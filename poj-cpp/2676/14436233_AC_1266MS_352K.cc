#include <stdio.h>
#include <string.h>

int rn[9][10], cn[9][10], bn[9][10], maps[9][9];

int getb(int r, int c)
{
        int rr = r/3;
        int cc = c/3;
        return rr*3 + cc;
}

int judge(int r, int c, int n)
{
        if(rn[r][n]) return 0;
        if(cn[c][n]) return 0;
        if(bn[getb(r, c)][n]) return 0;
        return 1;
}

int dfs()
{
        int i, j, k;
        for(i=0; i<9; i++) {
                for(j=0; j<9; j++) {
                        if(maps[i][j]==0) break;
                }
                if(j!=9) break;
        }
        if(i==9 && j==9) return 1;
        for(k=1; k<=9; k++) {
                 if(judge(i, j, k)) {
                        maps[i][j] = k;
                        rn[i][k] = 1;
                        cn[j][k] = 1;
                        bn[getb(i, j)][k] = 1;
                        if(dfs()) return 1;
                        rn[i][k] = 0;
                        cn[j][k] = 0;
                        bn[getb(i, j)][k] = 0;
                        maps[i][j] = 0;
                 }
        }
        return 0;
}

int main()
{
        int T, i, j;

        scanf("%d", &T);
        while(T--) {
                memset(rn, 0, sizeof(rn));
                memset(cn, 0, sizeof(cn));
                memset(bn, 0, sizeof(bn));
                memset(maps, 0, sizeof(maps));
                for(i=0; i<9; i++) {
                        getchar();
                        for(j=0; j<9; j++) {
                                int ch = getchar();
                                rn[i][ch-'0'] = 1;
                                cn[j][ch-'0'] = 1;
                                bn[getb(i, j)][ch-'0'] = 1;
                                maps[i][j] = ch-'0';
                        }
                }
                if(dfs()==0) return 0;
                for(i=0; i<9; i++) {
                        for(j=0; j<9; j++)
                                printf("%d", maps[i][j]);
                        printf("\n");
                }
        }

        return 0;
}
