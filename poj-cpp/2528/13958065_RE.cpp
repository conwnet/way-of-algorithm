#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct T{
        int i;
        int value;
        int num;
};

int cmp(T a, T b){
        return a.i<b.i;
}

int lazy[40010], flag[20000], N;
T fk[40000];

void build();
void update(int o, int L, int R, int l, int r, int c);
void cal(int o, int L, int R);
void pushdown(int o, int L, int R);

int main()
{
        int nCase, i, j, cnt, pos[20000][2], t, n;

        scanf("%d", &nCase);
        while(nCase--){
                scanf("%d", &N);
                for(i=0, cnt=0; i<N; i++){
                        scanf("%d%d", &pos[i][0], &pos[i][1]);
                        fk[cnt].i = pos[i][0];
                        fk[cnt++].value = i+1;
                        fk[cnt].i = pos[i][1];
                        fk[cnt++].value = -(i+1);
                }
                sort(fk, fk+cnt, cmp);
                n = fk[0].i;
                t = 1;
                for(i=0; i<N*2; i++){
                        if(fk[i].i!=n){
                                t++;
                                n = fk[i].i;
                        }
                        if(fk[i].value>0){
                                pos[fk[i].value-1][0] = t;
                        } else {
                                pos[-(fk[i].value+1)][1] = t;
                        }
                }
                build();
                for(i=0; i<N; i++){
                        update(1, 1, t, pos[i][0], pos[i][1], i+1);
                }
                memset(flag, 0, sizeof(flag));
                cal(1, 1, t);
                cnt = 0;
                for(i=0; i<20000; i++){
                        if(flag[i]) cnt++;
                }
                printf("%d\n", cnt);

        }

        return 0;
}

void build()
{
        memset(lazy, 0, sizeof(lazy));
}

void pushdown(int o, int L, int R)
{
        if(L<R){
                lazy[o*2] = lazy[o*2+1] = lazy[o];
                lazy[o] = 0;
        }
}

void update(int o, int L, int R, int l, int r, int c)
{
        if(lazy[o]) pushdown(o, L, R);
        if(l<=L && r>=R){
                lazy[o] = c;
        }else{
                int M = (L+R)/2;
                if(l<=M) update(o*2, L, M, l, r, c);
                if(r>M) update(o*2+1, M+1, R, l, r, c);
        }
}

void cal(int o, int L, int R)
{
        if(lazy[o]){
                flag[lazy[o]] = 1;
                return ;
        }
        if(L>=R) return ;
        int M = (L+R)/2;
        cal(o*2, L, M);
        cal(o*2+1, M+1, R);

}
