#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MOD = 1e8;
int dp[251][64], len[251], N;

void add(int *a, int &la, int *b, int lb)
{
        if(lb>la) la = lb;
        for(int i=0; i<lb; i++)
                a[i] += b[i];
        for(int i=0; i<la; i++) {
                if(a[i]>MOD) {
                        a[i+1] += a[i]/MOD;
                        a[i] %= MOD;
                }
        }
        if(a[la]) la++;
}

void print(int *a, int la)
{
        printf("%d", a[la-1]);
        for(int i=la-2; i>=0; i--)
                printf("%08d", a[i]);
        printf("\n");
}

void solve()
{
        for(int i=0; i<251; i++)
                len[i] = 1;
        dp[0][0] = dp[1][0] = 1;
        for(int i=2; i<251; i++) {
                add(dp[i], len[i], dp[i-1], len[i-1]);
                add(dp[i], len[i], dp[i-2], len[i-2]);
                add(dp[i], len[i], dp[i-2], len[i-2]);
        }
}

int main()
{
        solve();
        while(~scanf("%d", &N)) {
                print(dp[N], len[N]);
        }

        return 0;
}
