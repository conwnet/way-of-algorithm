#include <stdio.h>
#include <math.h>

int euler_phi(int n)
{
        int m = (int)(sqrt(n)+0.5);
        int ans = n;
        for(int i=2; i<=m; i++) {
                if(n%i==0) {
                        ans = ans/i * (i-1);
                        while(n%i==0) n /= i;
                }
        }
        if(n>1) ans = ans/n * (n-1);
        return ans;
}

int main()
{
        int n;

        while(scanf("%d", &n) && n) {
                printf("%d\n", euler_phi(n));
        }

        return 0;
}




