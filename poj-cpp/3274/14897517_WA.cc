#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int cow[100010], N, K, st[400010];

typedef pair<int, int> P;
P dat[100010];

void update(int o, int L, int R, int pos, int n)
{
        if(L==R) st[o] = n;
        else {
                int M = (L+R)>>1;
                if(pos<=M) update(o*2, L, M, pos, n);
                else update(o*2+1, M+1, R, pos, n);
                st[o] = st[o*2]^st[o*2+1];
        }
}

int query(int o, int L, int R)
{
        if(st[o]==(1<<K)-1) return R-L+1;
        if(L==R) return 0;
        int M = (L+R)>>1;
        int a = query(o*2, L, M);
        int b = query(o*2+1, M+1, R);
        return a>b ? a : b;
}

int ra[100010];

int cmp(int a, int b)
{
        return cow[a] < cow[b];
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=1; i<=N; i++)
                scanf("%d", &cow[i]);
        for(int i=1; i<=N; i++) {
                cow[i] ^= cow[i-1];
        }
        for(int i=0; i<=N; i++) dat[i] = P(cow[i], i);
        sort(dat, dat+N+1);
        int ans = 0;
        for(int i=0; i<=N; ) {
                P t = dat[i]; t.first += 1; t.second = 0;
                int j = lower_bound(dat, dat+N+1, t) - dat;
                ans = max(ans, dat[j-1].second-dat[i].second);
                i = j;
        }
        ///for(int i=0; i<N; i++) printf("%d ", cow[i]); printf("\n");
        ///for(int i=0; i<N; i++) printf("%d %d\n", dat[i].first, dat[i].second);
        printf("%d\n", ans);

        return 0;
}

/**<
7 3
7 6 7 2 1 4 2



 */


