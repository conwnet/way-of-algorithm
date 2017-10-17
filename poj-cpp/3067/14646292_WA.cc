#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
const int maxn = 1000005;

P p[maxn];
ll bit[1005];
int N, M, K;

inline int lowbit(int x)
{
        return x&-x;
}

void Add(int pos, int n)
{
        while(pos<=M) {
                bit[pos] += n;
                pos += lowbit(pos);
        }
}

ll Sum(int pos)
{
        ll sum = 0;
        while(pos>0) {
                sum += bit[pos];
                pos -= lowbit(pos);
        }
        return sum;
}

int main()
{
        int T;

        scanf("%d", &T);
        for(int nCase=1; nCase<=T; nCase++) {
                memset(bit, 0, sizeof(bit));
                scanf("%d%d%d", &N, &M, &K);
                for(int i=0; i<K; i++)
                        scanf("%d%d", &p[i].first, &p[i].second);
                sort(p, p+K);
                ll ans = 0;
                for(int i=K-1; i>=0; i--) {
                        if(0==Sum(p[i].second)-Sum(p[i].second-1))
                                Add(p[i].second, 1);
                        ans += Sum(p[i].second)-1;
                }
                printf("Test case %d: %lld\n", nCase, ans);
        }

        return 0;
}








