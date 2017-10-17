
#include <stdio.h>
#include <string.h>

int num1[50], num2[50], ans[100], l1, l2, l;

int main()
{
        char str[50];
        int i, j;

        l1 = 0;
        scanf("%s", str);
        for(i=0; str[i]; i++) {
                num1[l1++] = str[i]-'0';
        }
        l2 = 0;
        scanf("%s", str);
        for(i=0; str[i]; i++) {
                num2[l2++] = str[i]-'0';
        }
        memset(ans, 0, sizeof(ans));
        for(i=0; i<l1; i++) {
                for(j=0; j<l2; j++) {
                        ans[i+j] += num1[i]*num2[j];
                }
        }
        l = l1+l2-1;
        for(i=1; i<l; i++) {
               if(ans[i]>=10) {
                        ans[i-1] += ans[i]/10;
                        ans[i] %= 10;
                }
        }
        for(i=0; !ans[i] && i<l-1; i++);
        for( ; i<l; i++) printf("%d", ans[i]);

        return 0;
}