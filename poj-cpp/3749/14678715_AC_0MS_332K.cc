#include <stdio.h>
#include <string.h>

char maps[30] = "VWXYZABCDEFGHIJKLMNOPQRSTU";

int main()
{
        char str[10], ch;

        while(scanf("%s", str)) {
                if(!strcmp(str, "ENDOFINPUT"))
                        break;
                getchar();
                while((ch=getchar())!='\n')
                        if(ch<='Z' && ch>='A')
                                putchar(maps[ch-'A']);
                        else putchar(ch);
                putchar('\n');
                scanf("%s", str);
        }

        return 0;
}
