#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mata[512][512], matb[512][512], matc[512][512], N;

int get_int()
{
        int ch, sign = 1, ret = 0;
        while(ch=getchar())
                if(ch=='-' || ch<='9' && ch>='0') break;
        if(ch=='-') sign = -1;
        else ret = ch-'0';
        while(ch=getchar()) {
                if(ch<'0' || ch>'9') break;
                ret = ret*10 + ch-'0';
        }
        return sign*ret;
}

/**
int solve()
{
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        int s = 0;
                        for(int k=0; k<N; k++) {
                                s += mata[i][k]*matb[k][j];
                        }
                        if(s!=matc[i][j]) return 0;
                }
        }
        return 1;
}
*/

int solve()
{
        for(int i=0; i<50000; i++) {
                        int s = 0, r = rand()%N, c = rand()%N;
                        for(int k=0; k<N; k++) {
                                s += mata[r][k]*matb[k][c];
                        }
                        if(s!=matc[r][c]) return 0;
        }
        return 1;
}

int main()
{
        srand(13);
        N = get_int();
        for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                        mata[i][j] = get_int();
        for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                        matb[i][j] = get_int();
        for(int i=0; i<N; i++)
                for(int j=0; j<N; j++)
                        matc[i][j] = get_int();
        if(solve()) printf("YES\n");
        else printf("NO\n");

        return 0;
}
