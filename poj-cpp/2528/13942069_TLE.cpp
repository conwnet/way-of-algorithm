#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

int lzy[2000000], N, l, r;
set<int> s;

void fuck(int o){
    lzy[o*2] = lzy[o*2+1] = lzy[o];
    lzy[o] = 0;
}

void change(int o, int L, int R, int N);

void get(int o, int L, int R);

int main(){
    int nCase, i;

    scanf("%d", &nCase);
    while(nCase--){
        scanf("%d", &N);
        memset(lzy, 0, 1100000*4);
        for(i=1; i<=N; i++){
            scanf("%d%d", &l, &r);
            change(1, 1, 100000, i);
        }
        s.clear();
        get(1, 1, 110000);
        printf("%d\n", s.size());
    }

    return 0;
}

void change(int o, int L, int R, int n){
    if(L<R && lzy[o]) fuck(o);
    if(l<=L && r>=R) lzy[o] = n;
    else{
        int M = (L+R)/2;
        if(l<=M) change(o*2, L, M, n);
        if(r>M) change(o*2+1, M+1, R, n);
    }
}

void get(int o, int L, int R){

    if(lzy[o]){
        s.insert(lzy[o]);
    }
    else if(L==R) ;
    else{
        int M = (L+R)/2;
        get(o*2, L, M);
        get(o*2+1, M+1, R);
    }
}
