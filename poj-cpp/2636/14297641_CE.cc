#include <stdio.h>

int main()
{
    int sum, i, N锛孴, n锛�    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N);
        sum = 0;
        for(i=0; i<N; i++) {
            scanf("%d", &n);
            sum += n;
        }
        printf("%d\n", sum-n+1);
    }
    return 0;
}