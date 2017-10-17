#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str1[128];
char str2[128];
int dp1[128][128];
int dp2[128][128];

int main()
{
        int T;

        scanf("%d", &T);
        while(T--) {
                scanf("%s%s", str1+1, str2+1);
                int l1 = strlen(str1+1);
                int l2 = strlen(str2+1);
                dp1[0][0] = dp2[0][0] = 0;
                for(int i=1; i<=l1; i++) {
                        for(int j=1; j<=l2; j++) {
                                if(str1[i]==str2[j])
                                        dp1[i][j] = dp1[i-1][j-1] + 1;
                                else dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
                        }
                }
                for(int i=1; i<=l1; i++) {
                        for(int j=1; j<=l2; j++) {
                                if(str1[i]==str2[l2-j+1])
                                        dp2[i][j] = dp2[i-1][j-1] + 1;
                                else dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
                        }
                }
                printf("%s\n", max(dp1[l1][l2], dp2[l1][l2])==l2 ? "YES": "NO");
        }

        return 0;
}
