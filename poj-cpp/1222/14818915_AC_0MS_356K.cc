#include <stdio.h>
#include <string.h>

int maps[5][6], flip[5][6], ans[5][6];

int is_ok()
{
        for(int i=0; i<5; i++)
                for(int j=0; j<6; j++)
                        if(maps[i][j]+flip[i][j] & 1)
                                return 0;
        return 1;
}

void Flip(int r, int c)
{

        if(r-1>=0) flip[r-1][c] ^= 1;
        if(c-1>=0) flip[r][c-1] ^= 1;
        flip[r][c] ^= 1;
        if(r+1<5) flip[r+1][c] ^= 1;
        if(c+1<6) flip[r][c+1] ^= 1;
        ans[r][c] = 1;
}

int judge(int s)
{
        memset(ans, 0, sizeof(ans));
        memset(flip, 0, sizeof(flip));
        for(int i=0; i<6; i++) {
                if(s & 1<<i) {
                        Flip(0, i);
                }
        }
        for(int i=1; i<5; i++) {
                for(int j=0; j<6; j++) {
                        if(maps[i-1][j]+flip[i-1][j] & 1)
                                Flip(i, j);
                }
        }
        return is_ok();
}

int main()
{
        int T;

        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                printf("PUZZLE #%d\n", nC);
                for(int i=0; i<5; i++)
                        for(int j=0; j<6; j++)
                                scanf("%d", &maps[i][j]);
                for(int s=0; s<1<<6; s++)
                        if(judge(s)) break;
                for(int i=0; i<5; i++) {
                        printf("%d", ans[i][0]);
                        for(int j=1; j<6; j++)
                                printf(" %d", ans[i][j]);
                        printf("\n");
                }

        }

        return 0;
}
