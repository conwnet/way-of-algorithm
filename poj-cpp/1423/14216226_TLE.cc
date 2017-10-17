#include <stdio.h>
#include <math.h>

int solve(int n);

int main()
{
        int T, n;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &n);
                printf("%d\n", solve(n));
        }

        return 0;
}

int solve(int n)
{
        int i;

        double ans = 1;
        for(i=n; i>0; i--) {
                ans += log10((double)i);
        }
        return ans;

}

