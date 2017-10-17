#include <stdio.h>

int num[1000010], N;

int main()
{
        int i, a, b;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%d%d", &a, &b);
                num[i] = a+b;
        }
        for(i=N-1; i>0; i--) {
                if(num[i]>=10) {
                        num[i] -= 10;
                        num[i-1] += 1;
                }
        }
        for(i=0; i<N; i++) printf("%d", num[i]);

        return 0;
}
