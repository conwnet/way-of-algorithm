#include <stdio.h>

int main()
{
        int N, n, ans;

        while(~scanf("%d", &N)) {
                ans = n = 1;
                while(n%=N) {
                        n = n*10+1;
                        ans++;
                }
                printf("%d\n", ans);
        }

        return 0;
}
