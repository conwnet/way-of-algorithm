#include <stdio.h>

char str[15];

int main()
{
        while(scanf("%s", str) && str[0]-'0') {
                printf("%s: ", str);
                for(int i=0; str[i]; i++) {
                        if(str[i]>'4')
                                str[i]--;
                }
                int s = 0;
                for(int i=0; str[i]; i++) {
                        s *= 9;
                        s += str[i]-'0';
                }
                printf("%d\n", s);
        }

        return 0;
}
