#include <stdio.h>
#include <string.h>

inline int max(int a, int b) { return a>b?a:b; }

int lst[5][5] = { 5, -1, -2, -1, -3,
                 -1,  5, -3, -2, -4,
                  2, -3,  5, -2, -2,
                 -1, -2, -2,  5, -1,
                 -3, -4, -2, -1,  0 };

char str1[128], str2[128];
int L1, L2, ans[128][128];

int cal(char a, char b);
int get(char a);

int main()
{
        int T, i, j;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%s%d%s", &L1, str1+1, &L2, str2+1);
                memset(ans, 0, sizeof(ans));
                for(i=1; i<=L1; i++) ans[i][0] = ans[i-1][0]+cal(str1[i], ' ');
                for(i=1; i<=L2; i++) ans[0][i] = ans[0][i-1]+cal(' ', str2[i]);
                for(i=1; i<=L1; i++) {
                        for(j=1; j<=L2; j++) {
                                ans[i][j] = max(ans[i-1][j]+cal(str1[i], ' '), ans[i][j-1]+cal(' ', str2[j]));
                                ans[i][j] = max(ans[i][j], ans[i-1][j-1]+cal(str1[i], str2[j]));
                        }
                }
                printf("%d\n", ans[L1][L2]);
        }

        return 0;
}

int cal(char a, char b)
{
        return lst[get(a)][get(b)];
}
int get(char a)
{
        if(a=='A') return 0;
        if(a=='C') return 1;
        if(a=='G') return 2;
        if(a=='T') return 3;
        return 4;
}
