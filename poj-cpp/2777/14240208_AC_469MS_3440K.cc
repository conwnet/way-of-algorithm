#include <stdio.h>
#include <string.h>

int L, C, O, sum[610000], lazy[610000], color;

int init();
int update(int o, int L, int R, int l, int r, int n);
int query(int o, int L, int R, int l, int r);

int main()
{
        int l, r, n, i, ans;
        char cmd[5];

        scanf("%d%d%d", &L, &C, &O);
        lazy[1] = 1;
        while(O--) {
                scanf("%s%d%d", cmd, &l, &r);
                if(l>r) l^=r^=l^=r;
                if(cmd[0]=='C') {
                        scanf("%d", &n);
                        update(1, 1, L, l, r, n);
                } else {
                        color = 0;
                        query(1, 1, L, l, r);
                        //printf("%d\n", color);
                        for(ans=0; color!=0; color>>=1)
                                ans += color&1;
                        printf("%d\n", ans);
                }
                ///printf("--- "); for(i=1; i<2*L; i++) printf("%d ", sum[i]); printf("\n");
                ///printf("--- "); for(i=1; i<2*L; i++) printf("%d ", lazy[i]); printf("\n");
        }

        return 0;
}

int update(int o, int L, int R, int l, int r, int n)
{
        if(lazy[o]) {
                lazy[o*2] = lazy[o*2+1] = lazy[o];
                sum[o] = lazy[o];
                lazy[o] = 0;
        }
        if(l<=L && r>=R) { return lazy[o] = 1<<(n-1); }
        if(R<l || r<L) return sum[o];
        int M = (L+R)>>1;
        sum[o] = update(o*2, L, M, l, r, n)|update(o*2+1, M+1, R, l, r, n);
}

int query(int o, int L, int R, int l, int r)
{
        if(lazy[o]) {
                lazy[o*2] = lazy[o*2+1] = lazy[o];
                sum[o] = lazy[o];
                lazy[o] = 0;
        }
        if(l<=L && r>=R) { color |= sum[o]; return sum[o]; }
        if(R<l || r<L) return sum[o];
        int M = (L+R)>>1;
        sum[o] = query(o*2, L, M, l, r)|query(o*2+1, M+1, R, l, r);
}
