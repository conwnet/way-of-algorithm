#include <stdio.h>

const int maxn = 1e6+1;
long long fact[maxn], dp[maxn];

void sieve()
{
        for(int i=2; i*i<maxn; i++) {
                int c = 1;
                for(int j=i*2; j<maxn; j+=i)
                        fact[j] += c++;
        }
}

int main()
{
        sieve();
        dp[1] = 0;
        for(int i=2; i<maxn; i++) dp[i] = dp[i-1]+ i-1 - fact[i];
        int n;
        while(scanf("%d", &n) && n)
                printf("%lld\n", dp[n]);

        return 0;
}
