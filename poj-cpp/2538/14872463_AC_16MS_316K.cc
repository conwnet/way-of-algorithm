#include <stdio.h>
#include <string.h>

char S1[49] = {"`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,."};
char S2[49] = {"1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./"};
int maps[128];

int main()
{
        for(int i=0; i<43; i++)
                maps[S2[i]] = i;
        while(int ch=getchar()) {
                if(EOF==ch) break;
                if(ch==' ' || ch=='\n') putchar(ch);
                else putchar(S1[maps[ch]]);
        }

        return 0;
}
