#include <stdio.h>
#include <string.h>

int main()
{
        char str[1024];
        int l1, l2, num1[1024], num2[1024], T, i, j;

        scanf("%d", &T);
        while(T--) {
                memset(num1, 0, sizeof(num1));
                memset(num2, 0, sizeof(num2));
                scanf("%s", str);
                l1 = strlen(str);
                for(i=0; i<l1; i++) num1[i] = str[i]-'0';
                scanf("%s", str);
                l2 = strlen(str);
                for(i=0; i<l2; i++) num2[i] = str[i]-'0';
                j = l1>l2?l1:l2;
                for(i=0; i<j; i++) {
                        num1[i] += num2[i];
                        if(num1[i]>=10) { num1[i] -= 10; num1[i+1] += 1; }
                }
                for(i=0; !num1[i]; i++);
                for(; num1[i]; i++) printf("%d", num1[i]);
                printf("\n");
        }

        return 0;
}
