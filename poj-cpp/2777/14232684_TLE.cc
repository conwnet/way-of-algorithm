#include <stdio.h>
#include <string.h>

int ST[300001], L, T, O, ans, vst[35];

void update(int o, int L, int R, int l, int r, int n);
void query(int o, int L, int R, int l, int r);

int main()
{
        int l, r, n;
        char cmd[5];

        scanf("%d%d%d", &L, &T, &O);
        memset(ST, 0, sizeof(ST));
        ST[1] = 1;
        while(O--) {
                scanf("%s", cmd);
                if(cmd[0]=='C') {
                        scanf("%d%d%d", &l, &r, &n);
                        if(l>r) l^=r^=l^=r;
                        update(1, 1, L, l, r, n);
                } else {
                        scanf("%d%d", &l, &r);
                        ans = 0;
                        memset(vst, 0, sizeof(vst));
                        if(l>r) l^=r^=l^=r;
                        query(1, 1, L, l, r);
                        printf("%d\n", ans);
                }
        }

        return 0;
}

void update(int o, int L, int R, int l, int r, int n)
{
        if(l<=L && r>=R) { ST[o] = n; return ; }
        if(ST[o]) { ST[o*2] = ST[o*2+1] = ST[o]; ST[o] = 0; }
        int M = (L+R)>>1;
        if(l<=M) update(o*2, L, M, l, r, n);
        if(r>M) update(o*2+1, M+1, R, l, r, n);
}

void query(int o, int L, int R, int l, int r)
{
        if(l<=L && r>=R) {
                if(ST[o]!=0) {
                        if(!vst[ST[o]]) {
                                ans++;
                                vst[ST[o]] = 1;
                        }
                } else {
                        int M = (L+R)>>1;
                        query(o*2, L, M, l, r);
                        query(o*2+1, M+1, R, l, r);
                }
                return ;
        }
        if(ST[o]) { ST[o*2] = ST[o*2+1] = ST[o]; ST[o] = 0; }
        int M = (L+R)>>1;
        if(l<=M) query(o*2, L, M, l, r);
        if(r>M) query(o*2+1, M+1, R, l, r);
}
