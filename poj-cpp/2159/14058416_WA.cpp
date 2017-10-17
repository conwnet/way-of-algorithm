#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void change(char *str, int n);
int compare(char *str1, char *str2);

int main()
{
        char str1[102], str2[102];
        int i, j, l1, l2;

        scanf("%s%s", str1, str2);
        sort(str1, str1+strlen(str1));
        sort(str2, str2+strlen(str2));
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
        int l = strlen(str);

        for(int i=0; i<l; i++){
                str[i] += n;
                if(str[i]>'Z') str[i] -= 26;
        }
}

int compare(char *str1, char *str2)
{
        int l1 = strlen(str1);
      //  int l2 = strlen(str2);

        for(int i=0; i<l1; i++) {
                if(str1[i]!=str2[i]) return 0;
        }
        return 1;
}



