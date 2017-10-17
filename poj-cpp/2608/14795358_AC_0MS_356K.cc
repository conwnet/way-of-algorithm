#include <stdio.h>

int maps[26] = {0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2};

int main()
{
        char str[30];

        while(~scanf("%s", str)) {
                for(int i=0; str[i]; i++) {
                        if(!maps[str[i]-'A']) continue;
                        if(maps[str[i]-'A']==maps[str[i-1]-'A']) continue;
                        printf("%d", maps[str[i]-'A']);
                }
                printf("\n");
        }

        return 0;
}
