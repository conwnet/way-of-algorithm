#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cnt[102][102];

int main()
 {
        char str1[102], str2[102];
        int l1, l2, i, j;
        while(~scanf("%s%s", (str1+1), (str2+1))) {
                l1 = strlen(str1+1);
                l2 = strlen(str2+1);
                for (i=0; i<=l1; i++) {
                        cnt[0][i] = 0;
                }

                for (i=0; i<=l2; i++) {
                        cnt[i][0] = 0;
                }

                for (i=1; i<=l1; i++) {
                        for (j=1; j<=l2; j++) {
                                if(str1[i]==str2[j]) {
                                        cnt[i][j] = cnt[i-1][j-1]+1;
                                } else {
                                        cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
                                }
                        }
                }
                printf("%d\n", cnt[l1][l2]);
        }

        return 0;
}
