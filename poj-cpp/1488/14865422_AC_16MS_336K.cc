#include <stdio.h>

int main()
{
        int ch, ok = 0;

        while(ch=getchar()) {
                if(ch==EOF) break;
                if(ch=='"') {
                        if(ok==0) printf("``");
                        else printf("''");
                        ok ^= 1;
                } else putchar(ch);
        }

        return 0;
}
