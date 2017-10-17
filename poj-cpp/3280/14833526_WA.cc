#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[2048][2048], add[30], del[30], N, M;
char str[2048];


int main()
{
        char s[10];
        scanf("%d%d", &N, &M);
        scanf("%s", str+1);
        for(int i=0; i<N; i++) {
                scanf("%s", s);
                scanf("%d%d", &add[s[0]-'a'], &del[s[0]-'a']);
        }
        for(int i=1; i<=M; i++) {
                for(int j=1; j<=M; j++) {
                        if(str[i]==str[j]) dp[i][j] = dp[i-1][j-1];
                        else dp[i][j] = min(dp[i][j-1]+del[str[j]-'a'],
                                            dp[i][j-1]+add[str[j]-'a']);
                }
        }
        printf("%d\n", dp[1][M]);

        return 0;
}

