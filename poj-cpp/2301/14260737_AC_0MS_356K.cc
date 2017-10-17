#include <stdio.h>

int main()
{
        int T, a, b;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &a, &b);
                if(a>=b && (a+b)%2==0)
                        printf("%d %d\n", (a+b)/2, a-(a+b)/2);
                else printf("impossible\n");
        }

        return 0;
}
