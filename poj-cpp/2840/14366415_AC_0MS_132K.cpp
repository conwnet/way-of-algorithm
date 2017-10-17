#include <stdio.h>

int main()
{
        int hour, minute, T;

        scanf("%d", &T);
        while(T--) {
                scanf("%d:%d", &hour, &minute);
                if(minute!=0) printf("0\n");
                else {
                        if(hour>12) printf("%d\n", hour-12);
                        else printf("%d\n", hour+12);
                }
        }

        return 0;
}
