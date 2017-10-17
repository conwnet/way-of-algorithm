#include <stdio.h>

int num1[1000010], num2[1000010], N;

int main()
{
        int i;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%d%d", &num1[i], &num2[i]);
        }
        for(i=N-1; i>=0; i--) {
                num1[i] += num2[i];
        }
        for(i=N-1; i>0; i--) {
                if(num1[i]>=10) {
                        num1[i] -= 10;
                        num1[i-1] += 1;
                }
        }
        for(i=0; i<N; i++) printf("%d", num1[i]);

        return 0;
}
