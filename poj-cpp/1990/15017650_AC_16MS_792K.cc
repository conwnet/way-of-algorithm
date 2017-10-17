#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
const int maxn = 20100;
int N;
P cow[maxn];
ll dif[maxn], bit[maxn+1];

inline int low_bit(int x)
{
        return x & -x;
}

void Add(int pos, ll n)
{
        while(pos<=maxn) {
                bit[pos] += n;
                pos += low_bit(pos);
        }
}

ll Sum(int pos)
{
        ll ret = 0;
        while(pos>0) {
                ret += bit[pos];
                pos -= low_bit(pos);
        }
        return ret;
}

int cnt[maxn+1];
void Add1(int pos)
{
        while(pos<=maxn) {
                cnt[pos] += 1;
                pos += low_bit(pos);
        }
}

int Cnt(int pos)
{
        int ret = 0;
        while(pos>0) {
                ret += cnt[pos];
                pos -= low_bit(pos);
        }
        return ret;
}

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d%d", &cow[i].first, &cow[i].second);
        sort(cow, cow+N);
        ll ans = 0;
        memset(bit, 0, sizeof(bit));
        for(int i=0; i<N; i++) {
                ans += cow[i].first * (cow[i].second*(Cnt(cow[i].second)*2-Cnt(maxn))
                                        + Sum(maxn)-Sum(cow[i].second)*2);
                Add(cow[i].second, cow[i].second); Add1(cow[i].second);
        }
        printf("%lld\n", ans);

        return 0;
}
