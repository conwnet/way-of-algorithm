#include <stdio.h>

int main()
{
        int i, S, sum;

        scanf("%d", &S);
        for(i=1, sum=0; ; i++) {
                sum += i;
                if(sum>=S && (sum-S)%2==0) break;
        }
        printf("%d\n", i);

        return 0;
}
