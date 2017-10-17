#include <stdio.h>

const int maxn = 1e6+1;
int fact[maxn], prime[maxn];
long long dp[maxn];

void sieve()
{
        for(int i=2; i<maxn; i++) {
                if(!fact[i])
                for(int j=i; j<maxn; j+=i) {
                        if(!fact[j]) fact[j] = j;
                        fact[j] = fact[j] / i * (i-1);
                }
        }
}

int main()
{
        sieve();
        dp[1] = 0;
        for(int i=2; i<maxn; i++) dp[i] = dp[i-1] + fact[i];
        int n;
        while(scanf("%d", &n) && n)
                printf("%lld\n", dp[n]);

        return 0;
}
