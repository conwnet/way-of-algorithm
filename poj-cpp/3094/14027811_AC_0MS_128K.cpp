#include <stdio.h>
#include <string.h>

int main()
{
        char str[1024];
        int arr[1024], i, l, sum;

        while(gets(str) && str[0]!='#') {
                l = strlen(str);
                sum = 0;
                for(i=0; i<l; i++) {
                        if(str[i]==' ') continue;
                        sum += (str[i]-'A'+1)*(i+1);
                }
                printf("%d\n", sum);
        }

        return 0;
}
