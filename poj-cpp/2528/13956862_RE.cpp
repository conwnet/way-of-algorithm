#include <stdio.h>
#include <string.h>

int lazy[11000001], flag[20000], N;

void build();
void update(int o, int L, int R, int l, int r, int c);
void cal(int o, int L, int R);
void pushdown(int o, int L, int R);

int main()
{
        int nCase, i, l, r, cnt;

        scanf("%d", &nCase);
        while(nCase--){
                scanf("%d", &N);
                build();
                for(i=1; i<=N; i++){
                        scanf("%d%d", &l, &r);
                        update(1, 1, 11000000, l, r, i);
                }
                memset(flag, 0, sizeof(flag));
                cal(1, 1, 11000000);
                cnt = 0;
                for(i=1; i<=15000; i++){
                        if(flag[i]) cnt++;
                }
                printf("%d\n", cnt);
        }

        return 0;
}

void build()
{
        memset(lazy, 0, 10000001*4);
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