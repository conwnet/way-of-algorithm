#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char cmap[35][6] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
"..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
"--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
"-.--", "--..", "..--", ".-.-", "---.", "----"
};

char str[128], mor[1024];
int len, num[128];

int finds(char *ss)
{
        for(int i=0; i<30; i++) {
                if(0==strcmp(ss, cmap[i])) return i;
        }
        return -1;
}

int main()
{
        int T;
        char ts[6];
        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%s", str);
                mor[0] = 0;
                len = strlen(str);
                for(int i=0; i<len; i++) {
                        int idx;
                        if(str[i]=='_') idx = 26;
                        else if(str[i]==',') idx = 27;
                        else if(str[i]=='.') idx = 28;
                        else if(str[i]=='?') idx = 29;
                        else idx = str[i]-'A';
                        num[i] = strlen(cmap[idx]);
                        strcat(mor, cmap[idx]);
                }
                printf("%d: ", nC);
                int p = 0, j;
                for(int i=len-1; i>=0; i--) {
                        for(j=0; j<num[i]; j++)
                                ts[j] = mor[j+p];
                        ts[j] = 0;
                        p += num[i];
                        int idx = finds(ts);
                        if(idx==26) putchar('_');
                        else if(idx==27) putchar(',');
                        else if(idx==28) putchar('.');
                        else if(idx==29) putchar('?');
                        else putchar('A'+idx);
                }
                putchar('\n');
        }

        return 0;
}
