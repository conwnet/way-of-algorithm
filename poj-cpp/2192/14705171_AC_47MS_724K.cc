#include <stdio.h>
#include <string.h>

int dp[205][205][2];
char S1[205], S2[205], T[405];

int main()
{
        int nT;

        scanf("%d", &nT);
        for(int nC=1; nC<=nT; nC++) {
                scanf("%s%s%s", S1+1, S2+1, T+1);
                int l1 = strlen(S1+1);
                int l2 = strlen(S2+1);
                memset(dp, 0, sizeof(dp));
                dp[0][0][0] = dp[0][0][1] = 1;
                for(int i=0; i<=l1; i++) {
                        for(int j=0; j<=l2; j++) {
                                if(i>0 && T[i+j]==S1[i] && (dp[i-1][j][0] || dp[i-1][j][1]))
                                        dp[i][j][0] = 1;
                                if(j>0 && T[i+j]==S2[j] && (dp[i][j-1][0] || dp[i][j-1][1]))
                                        dp[i][j][1] = 1;
                        }
                }
                if(dp[l1][l2][0] || dp[l1][l2][1])
                        printf("Data set %d: yes\n", nC);
                else printf("Data set %d: no\n", nC);
        }

        return 0;
}






