#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 10005;

int N, arr[maxn];

ll cal(int l, int r)
{
        ll ans = 0;
        for(int i=l; i<=r; i++) {
                ans += arr[i]-arr[l];
        }
        return ans;
}

ll solve(int n)
{
        ll ans = 0;

        for(int i=1; i<=n/2; i++) {
                ans += cal(1, i) + cal(i, n);
        }
        ans <<= 1;
        if(n&1) ans += cal(1, n/2+1) + cal(n/2+1, n);
        return ans;
}

int main()
{
        scanf("%d", &N);
        arr[0] = 0;
        for(int i=1; i<=N; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr+N+1);
        printf("%lld\n", solve(N));

        return 0;
}
