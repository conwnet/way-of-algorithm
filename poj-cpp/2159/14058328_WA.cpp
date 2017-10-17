#include <stdio.h>
#include <string.h>

void change(char *str, int n);
int compare(char *str1, char *str2);

int main()
{
        char str1[102], str2[102];
        int i, j, l1, l2;

        scanf("%s%s", str1, str2);
        if(compare(str1, str2)) {
                printf("YES\n");
                return 0;
        }
        for(i=1; i<26; i++) {
                change(str1, 1);
                if(compare(str1, str2)) {
                        printf("YES\n");
                        return 0;
                }
        }
        printf("NO\n");

        return 0;
}

void change(char *str, int n)
{
        int i, l = strlen(str);

        for(i=0; i<l; i++) {
                str[i] += n;
                if(str[i]>'Z') str[i] -= 26;
        }
}

int compare(char *str1, char *str2)
{
        int l1, l2, i, j, vst[102];

        l1 = strlen(str1);
        l2 = strlen(str2);
        memset(vst, 0, sizeof(vst));
        for(i=0; i<l1; i++) {
                for(j=0; j<l2; j++) {
                        if(vst[j]) continue;
                        if(str2[j]==str1[i]) {
                                vst[j] = 1;
                                break;
                        }
                }
        }
        for(i=0; i<l1; i++) if(!vst[i]) return 0;
        return 1;
}
