#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int N;
ll arr[40];
P ab[1<<20];

ll Abs(ll a)
{
        if(a>0) return a;
        return -a;
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        scanf("%lld", &arr[i]);
                int m = N>>1;
                int cnt = 0;
                for(int i=0; i<1<<m; i++) {
                        ll sum = 0;
                        int n = 0;
                        for(int j=0; j<m; j++) {
                                if(i & 1<<j) {
                                        sum += arr[j];
                                        n++;
                                }
                        }
                        ab[cnt++] = P(sum, n);
                }
                sort(ab, ab+cnt);
                for(int i=0; i<1<<m; i++)
                        if(ab[i].first==ab[i-1].first)
                                ab[i].second = ab[i-1].second;
                P ans = P(INF, 40);
                for(int i=0; i<1<<(N-m); i++) {
                        ll sum = 0;
                        int n = 0;
                        for(int j=0; j<(N-m); j++) {
                                if(i & 1<<j) {
                                        sum += arr[m+j];
                                        n++;
                                }
                        }
                        int t = lower_bound(ab, ab+cnt, P(-sum, 0)) - ab;
                        if(ab[t].second+n>0)
                                ans = min(ans, P(Abs(sum+ab[t].first), n+ab[t].second));
                        if(ab[t-1].second+n>0 && t>0)
                                ans = min(ans, P(Abs(sum+ab[t-1].first), n+ab[t].second));
                }
                printf("%lld %d\n", ans.first, ans.second);
        }

        return 0;
}