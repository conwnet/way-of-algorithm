#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Node {
        int lc, rc, mc;
        int ln, rn, mn;
};

const int maxn = 100001;

Node len[maxn*4];

void update(int o, int L, int R, int pos, int n)
{
        if(L==R) {
                len[o].lc = len[o].rc = len[o].mc = 1;
                len[o].ln = len[o].rn = len[o].mn = n;
                return ;
        }
        int M = (L+R) >> 1;
        if(pos<=M) update(o*2, L, M, pos, n);
        else update(o*2+1, M+1, R, pos, n);

        if(len[o*2].lc==M-L+1 && len[o*2].ln==len[o*2+1].ln) {
                len[o].lc = len[o*2].lc + len[o*2+1].lc;
                len[o].ln = len[o*2].ln;
        } else {
                len[o].lc = len[o*2].lc;
                len[o].ln = len[o*2].ln;
        }

        if(len[o*2+1].rc==R-M && len[o*2+1].rn==len[o*2].rn) {
                len[o].rc = len[o*2+1].rc + len[o*2].rc;
                len[o].rn = len[o*2+1].rn;
        } else {
                len[o].rc = len[o*2+1].rc;
                len[o].rn = len[o*2+1].rn;
        }

        if(len[o*2].mc > len[o*2+1].mc) {
                len[o].mc = len[o*2].mc;
                len[o].mn = len[o*2].mn;
        } else {
                len[o].mc = len[o*2+1].mc;
                len[o].mn = len[o*2+1].mn;
        }

        if(len[o*2].rn==len[o*2+1].ln && len[o*2].rc+len[o*2+1].lc>len[o].mc) {
                len[o].mc = len[o*2].rc + len[o*2+1].lc;
                len[o].mn = len[o*2].rn;
        }

}

int query(int o, int L, int R, int l, int r)
{
        if(l<=L && r>=R)
                return len[o].mc;
        int M = (L+R) >> 1;
        int a = 0; int b = 0;
        if(l<=M) a = query(o*2, L, M, l, r);
        if(r>M) b = query(o*2+1, M+1, R, l, r);
        return a>b ? a : b;
}

int N, Q;

int main()
{
        int l, r, n;

        while(scanf("%d", &N) && N) {
                memset(len, 0, sizeof(len));
                scanf("%d", &Q);
                for(int i=1; i<=N; i++) {
                        scanf("%d", &n);
                        update(1, 1, N, i, n);
                }
                while(Q--) {
                        scanf("%d%d", &l, &r);
                        printf("%d\n", query(1, 1, N, l, r));
                }
        }

        return 0;
}
