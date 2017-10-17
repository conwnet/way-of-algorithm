#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Build{
        int l, r, h;
}build[41000];

int cmp(Build A, Build B)
{
        if(A.l!=B.l)
                return A.l < B.l;
        return A.r < B.r;
}

int main()
{
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d%d%d", &build[i].l, &build[i].r, &build[i].h);
        sort(build, build+N, cmp);
        for(int i=1; i<N; i++) {
                if(build[i-1].r > build[i].l) {
                        if(build[i-1].h > build[i].h)
                                build[i].l = build[i-1].r;
                        else build[i-1].r = build[i].l;
                }
        }
        ll ans = 0;
        for(int i=0; i<N; i++) {
                if(build[i].l<build[i].r)
                        ans += (ll)(build[i].r-build[i].l) * build[i].h;
        }
        printf("%lld\n", ans);

        return 0;
}
