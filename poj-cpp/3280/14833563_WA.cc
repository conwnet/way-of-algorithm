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
        for(int i=M; i>0; i--) {
                for(int j=1; j<=M; j++) {
                        if(str[i]==str[j]) dp[i][j] = dp[i+1][j-1];
                        else {
                                int a = dp[i][j-1] + min(add[str[j]-'a'], del[str[j]-'a']);
                                int b = dp[i+1][j] + min(add[str[i]-'a'], del[str[i]-'a']);
                                dp[i][j] = min(a, b);
                        }
                }
        }
        printf("%d\n", dp[1][M]);

        return 0;
}









