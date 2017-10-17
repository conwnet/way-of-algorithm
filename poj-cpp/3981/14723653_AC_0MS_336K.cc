#include <stdio.h>
#include <string.h>

int main()
{
        char str[1024];

        while(gets(str)) {
                int l = strlen(str);
                for(int i=0; i<l; i++) {
                        if(i<l-2 && str[i]=='y' && str[i+1]=='o' && str[i+2]=='u') {
                                printf("we"); i += 2;
                        } else putchar(str[i]);
                }
                putchar('\n');
        }

        return 0;
}
