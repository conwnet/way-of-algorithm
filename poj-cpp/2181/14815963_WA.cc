#include <stdio.h>

int main()
{
    int N, n, ans = 0;
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &n);
        if(i%2) ans += n;
    }
    printf("%d\n", ans);

    return 0;
}