#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int num[15000][15000];

int main()
{
        char str1[150000], str2[150000];
        int l1, l2, i, j, cnt;

        while(~scanf("%s%s", str1+1, str2+1)){
                l1 = strlen(str1+1);
                l2 = strlen(str2+1);
                memset(num, 0, sizeof(num));
                for(i=1; i<=l1; i++){
                        for(j=1; j<=l2; j++){
                                if (str1[i] == str2[j]) {
                                        num[i][j] = num[i-1][j-1] + 1;
                                } else {
                                        num[i][j] = max(num[i-1][j], num[i][j-1]);
                                }
                        }
                }
                if(num[l1][l2]==l1) printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}
