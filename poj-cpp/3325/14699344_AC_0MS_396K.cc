#include <stdio.h>
#include <string.h>

int main()
{
        int N, n, sum, maxs, mins;

        while(scanf("%d", &N) && N) {
                sum = 0; mins = 1024; maxs = -1;
                for(int i=0; i<N; i++) {
                        scanf("%d", &n);
                        sum += n;
                        if(n>maxs) maxs = n;
                        if(n<mins) mins = n;
                }
                printf("%d\n", (sum-maxs-mins)/(N-2));
        }

        return 0;
}
