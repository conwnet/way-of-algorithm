#include <stdio.h>
#include <string.h>

int cnt[1024];

int gcd(int a, int b)
{
        return b ? gcd(b, a%b) : a;
}

void solve()
{
        for(int i=1; i<1001; i++) {
                cnt[i] = cnt[i-1];
                for(int j=0; j<=i; j++) {
                        if(gcd(i, j)==1) {
                                if(i==j) cnt[i] += 1;
                                else cnt[i] += 2;
                        }
                }
        }
}

int main()
{
        int T, n;
        solve();
        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%d", &n);
                printf("%d %d %d\n", nC, n, cnt[n]);
        }

        return 0;
}
