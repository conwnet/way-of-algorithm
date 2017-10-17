#include <stdio.h>
#include <string.h>

int tree[300000], L, T, O, cnt, color[30000];

void build();
void update(int o, int L, int R, int l, int r, int c);
void cal(int o, int L, int R, int l, int r);
void pushdown(int o, int L, int R);
void query(int o, int L, int R);

int main()
{
        int l, i, r, c;
        char cmd[5];

        scanf("%d%d%d", &L, &T, &O);
        build();
        while(O--){
                scanf("%s", cmd);
                if(cmd[0]=='C'){
                        scanf("%d%d%d", &l, &r, &c);
                        update(1, 1, T, l, r, c);
                } else {
                        scanf("%d%d", &l, &r);
                        cnt = 0;
                        memset(color, 0, sizeof(color));
                        cal(1, 1, T, l, r);
                        for(i=0; i<=T; i++)
                                if(color[i]) cnt++;
                        printf("%d\n", cnt);
                }
        }

        return 0;
}

void build()
{
        for(int i=0; i<=T*2; i++){
                tree[i] = 1;
        }
}

void pushdown(int o, int L, int R)
{
        if(L<R){
                tree[o*2] = tree[o*2+1] = tree[o];
                tree[o] = 0;
        }
}

void update(int o, int L, int R, int l, int r, int c)
{
        if(tree[o]) pushdown(o, L, R);
        if(l<=L && r>=R){
                tree[o] = c;
        } else {
                int M = (L+R)/2;
                if(l<=M) update(o*2, L, M, l, r, c);
                if(r>M) update(o*2+1, M+1, R, l, r, c);
        }
}

void cal(int o, int L, int R, int l, int r)
{
        if(l<=L && r>=R){
                query(o, L, R);
        } else {
                int M = (L+R)/2;
                if(l<=M) cal(o*2, L, M, l, r);
                if(r>M) cal(o*2+1, M+1, R, l, r);
        }
}

void query(int o, int L, int R)
{
        if(tree[o]){
                color[tree[o]] = 1;
                return ;
        }
        if(L>=R) return ;
        int M = (L+R)/2;
        query(o*2, L, M);
        query(o*2+1, M+1, R);
}
