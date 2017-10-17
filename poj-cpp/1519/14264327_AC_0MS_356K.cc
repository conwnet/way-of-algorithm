#include <stdio.h>

int main()
{
        int n, sum, i;
        char str[3000];

        while(scanf("%s", &str)) {
                if(str[0]=='0') break;
                n = 0;
                for(i=0; str[i]!='\0'; i++) n += str[i]-'0';
                while(n>9) {
                        sum = 0;
                        while(n/10) {
                                sum += n%10;
                                n /= 10;
                        }
                        n += sum;
                }
                printf("%d\n", n);
        }

        return 0;
}
