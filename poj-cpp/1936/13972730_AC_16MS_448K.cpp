#include <stdio.h>
#include <string.h>


int main()
{
        char str1[150000], str2[150000];
        int l1, l2, i, j, cnt;

        while (~scanf("%s%s", str1, str2)){
                l2 = strlen(str2);
                for (i = j = 0; i < l2 && str1[j] != '\0'; i++){
                        if (str1[j] == str2[i]) {
                                j++;
                        }
                }


                if (str1[j]=='\0') printf("Yes\n");
                else printf("No\n");
        }

        return 0;
}