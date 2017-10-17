#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int num[maxn], dat[20][maxn], cnt[20][maxn];
int N, M, K;

void build(int L, int R, int o)
{
        if(L==R) return ;
        int M = (L+R)>>1;
        int lp = L, rp = M+1;
        for(int i=L; i<=R; i++) {
                if(dat[o][i]<=num[M]) {
                        cnt[o][i] = cnt[o][i-1]+1;
                        dat[o+1][lp++] = dat[o][i];
                } else {
                        cnt[o][i] = cnt[o][i-1];
                        dat[o+1][rp++] = dat[o][i];
                }
        }
        build(L, M, o+1);
        build(M+1, R, o+1);
}

int _l, _r, _x;
int query(int L, int R, int o)
{
        if(L==R) return dat[o][L];
        int M = (L+R)>>1;
        if(cnt[o][_r]-cnt[o][_l-1]>=_x) {
                _l = L+cnt[o][_l-1]-cnt[o][L-1];
                _r = L+cnt[o][_r]-1-cnt[o][L-1];
                return query(L, M, o+1);
        } else {
                _x -= cnt[o][_r]-cnt[o][_l-1];
                _l = M+1 + (_l-1-cnt[o][_l-1]);
                _r = M+1 + (_r-cnt[o][_r]) - 1;
                return query(M+1, R, o+1);
        }
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++) {
                scanf("%d", &num[i]);
                dat[1][i] = num[i];
        }
        sort(num+1, num+1+N);
        build(1, N, 1);
        for(int i=1; i<=7; i++) printf("%d ", cnt[3][i]); printf("\n");
        while(M--) {
                scanf("%d%d%d", &_l, &_r, &_x);
                printf("%d\n", query(1, N, 1));
        }


        return 0;
}
