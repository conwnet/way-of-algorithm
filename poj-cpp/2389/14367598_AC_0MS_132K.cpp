#include <stdio.h>
#include <string.h>

int num1[10], num2[10], ans[20], l1, l2, l;

void read_int(int *num, int *l)
{
        char str[50];
        int i, j, sl, sum;

        scanf("%s", str);
        sl = strlen(str);
        *l = 0;
        if(sl%4==0) i = 0;
        else {
                for(i=0, sum=0; i<sl%4; i++) {
                        sum = sum*10 + str[i]-'0';
                }
                num[(*l)++] = sum;
        }
        for(sum=0, j=0; str[j+i]; j++) {
                sum = sum*10 + str[i+j]-'0';
                if((j+1)%4==0) {
                        num[(*l)++] = sum;
                        sum = 0;
                }
        }
}

int main()
{
        char str[50];
        int i, j, sum;

        read_int(num1, &l1);
        read_int(num2, &l2);
        memset(ans, 0, sizeof(ans));
        for(i=0; i<l1; i++) {
                for(j=0; j<l2; j++) {
                        ans[i+j] += num1[i]*num2[j];
                }
        }
        l = l1+l2-1;
        for(i=l-1; i>0; i--) {
               if(ans[i]>=10000) {
                        ans[i-1] += ans[i]/10000;
                        ans[i] %= 10000;
                }
        }
        printf("%d", ans[0]);
        for(i=1; i<l; i++) printf("%04d", ans[i]);

        return 0;
}
