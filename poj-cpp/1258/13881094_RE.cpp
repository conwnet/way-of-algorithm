#include <stdio.h>
#include <algorithm>

using namespace std;

int u[128], v[128], w[128], N, cnt, r[16384], e[16384], M;

int kruskal();
int cmp(int a, int b){
    return w[a]<w[b];
}


int findroot(int x){
    return r[x]==x?x:findroot(r[x]);
}

int main(){
    int i, j, t;

    while(~scanf("%d", &N)){
        M = 0;
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(i==j) scanf("%d", &t);
                else {
                    u[M] = i;
                    v[M] = j;
                    scanf("%d", &w[M]);
                    M++;
                }
            }
        }
        cnt = 0;
        kruskal();
        printf("%d\n", cnt);
    }
    return 0;
}

int kruskal(){
    int i, t, x, y;

    for(i=0; i<M; i++) r[i] = i;
    for(i=0; i<M; i++) e[i] = i;
    sort(e, e+M, cmp);
    for(i=0; i<M; i++){
        t = e[i];
        x = findroot(u[t]);
        y = findroot(v[t]);

        if(x!=y){
            cnt += w[t];
            r[x] = y;
        }
    }
    return cnt;
}
