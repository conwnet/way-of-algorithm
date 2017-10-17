#include <stdio.h>

int main()
{
        int T, n, sum;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &n);
                for(sum=0; n/5; n/=5) sum += n/5;
                printf("%d\n", sum);
        }

        return 0;
}
