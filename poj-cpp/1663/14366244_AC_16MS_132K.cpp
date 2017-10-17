#include <stdio.h>

int main()
{
        int x, y, T;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &x, &y);
                if(x-y!=0 && x-y!=2) printf("No Number\n");
                else {
                        if(x==y) {
                                if(x&1) printf("%d\n", x*2-1);
                                else printf("%d\n", x*2);
                        } else {
                                if(x&1) printf("%d\n", x*2-3);
                                else printf("%d\n", x*2-2);
                        }
                }
        }

        return 0;
}
