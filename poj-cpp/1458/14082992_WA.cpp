#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char str1[1100], str2[1100];
int cnt[1024][1024];

int main()
{
        int l1, l2, i, j;

        scanf("%s%s", str1, str2);
        l1 = strlen(str1);
        l2 = strlen(str2);
        memset(cnt, 0, sizeof(cnt));
        for(i=1; i<=l1; i++) {
                for(j=1; j<=l2; j++) {
                        if(str1[i-1]==str2[j-1]) cnt[i][j] = cnt[i-1][j-1]+1;
                        else cnt[i][j] = max(cnt[i-1][j], cnt[i][j-1]);
                }
        }
        printf("%d\n", cnt[l1][l2]);


        return 0;
}
