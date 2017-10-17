#include <stdio.h>
#include <string.h>

int mata[512][512], matb[512][512], mat[512][512], matc[512][512], N;

int get_int()
{
        int ch, n;
        while(ch=getchar())
                if(ch<='9' && ch>='0') break;
        n = ch - '0';
        while(ch=getchar()) {
                if(ch>'9' || ch<'0') break;
                n = n*10 + ch-'0';
        }
        return n;
}

int solve()
{
        for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                        for(int k=0; k<N; k++)
                                mat[i][j] += mata[i][k]*matb[k][j];
                        if(mat[i][j]!=matc[i][j]) return 0;
                }
        }
        return 1;
}

int main()
{
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
