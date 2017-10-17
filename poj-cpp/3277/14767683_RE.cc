#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
const int maxn = 40010;
ll sum[maxn*4], lazy[maxn*4];
int bud[40010][3], N;
int hsh[80010], hcnt = 0;

void push_down(int o, int L, int R)
{
        int M = (L+R) >> 1;
        ll v = lazy[o] / (R-L+1);
        if(L!=R) {
                lazy[o*2] = v*(hsh[M+1]-hsh[L]);
                lazy[o*2+1] = v*(hsh[R+1]-hsh[M+1]);
        }
        sum[o] = lazy[o];
        lazy[o] = 0;
}
int _l, _r, _n;
void update(int o, int L, int R)
{
        if(lazy[o]) push_down(o, L, R);
        if(_l<=L && _r>=R) {
                ll s = (hsh[R+1]-hsh[L]) * _n;
                if(s>sum[o]) {
                        lazy[o] = s;
                        push_down(o, L, R);
                }
                return ;
        }
        if(_l>R || _r<L) return ;
        int M = (L+R) >> 1;
        update(o*2, L, M);
        update(o*2+1, M+1, R);
        sum[o] = sum[o*2] + sum[o*2+1];
}

int main()
{
        int n;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%d%d%d", &bud[i][0], &bud[i][1], &bud[i][2]);
                hsh[++hcnt] = bud[i][0];
                hsh[++hcnt] = bud[i][1];
        }
        sort(hsh+1, hsh+1+hcnt);
        hcnt = unique(hsh+1, hsh+1+hcnt) - hsh-1;
        for(int i=0; i<N; i++) {
                n = lower_bound(hsh+1, hsh+1+hcnt, bud[i][0]) - hsh;
                bud[i][0] = n;
                n = lower_bound(hsh+1, hsh+1+hcnt, bud[i][1]) - hsh;
                bud[i][1] = n;
        }
        for(int i=0; i<N; i++) {
                _l = bud[i][0];
                _r = bud[i][1]-1;
                _n = bud[i][2];
                update(1, 1, hcnt);
        }
        if(lazy[1]) push_down(1, 1, hcnt);
        printf("%lld\n", sum[1]);

        return 0;
}
