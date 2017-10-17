#include <stdio.h>

int main()
{
        int N, i, maxs, flag, a, b;

        while(scanf("%d", &N) && N) {
                flag = 0; maxs = 8;
                for(i=1; i<=N; i++) {
                        scanf("%d%d", &a, &b);
                        if(a+b>maxs) {
                                maxs = a+b;
                                flag = i;
                        }
                }
                printf("%d\n", flag);
        }

        return 0;
}
