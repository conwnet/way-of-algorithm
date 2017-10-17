#include <stdio.h>
#include <string.h>

int stk[510000];

int get_length(char str[]);

int main()
{
        int i;
        char str[50];

        memset(stk, 0, sizeof(stk));
        while(~scanf("%s", str)) {
                stk[get_length(str)] ++;
        }
        int cnt = 0;
        for(i=0; i<510000; i++) if(stk[i]%2) cnt++;
        if(cnt>2) printf("Impossible\n");
        else printf("Possible\n");

        return 0;
}

int get_length(char str[])
{
        int sum = 0;

        for(int i=0; str[i]!='\0'; i++) {
                sum += str[i];
        }
        sum *= sum;
        return sum%499979;
}
