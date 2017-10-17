
#include <stdio.h>
#include <algorithm>
#define INF 2000000

using namespace std;

int N, Q, A[65536], Max[131072], Min[131072];

void initSegTree(int o, int s, int e);
int queMax(int o, int s, int e, int l, int r);
int queMin(int o, int s, int e, int l, int r);

int main(){
    int i, a, b;

    scanf("%d%d", &N, &Q);
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    initSegTree(1, 0, N-1);
    while(Q--){
        scanf("%d%d", &a, &b);
        printf("%d\n", queMax(1, 0, N-1, a-1, b-1)-queMin(1, 0, N-1, a-1, b-1));
    }

    return 0;
}

void initSegTree(int o, int s, int e){
    int m = (s+e)>>1;

    if(s==e){
        Min[o] = A[s];
        Max[o] = A[s];
        return ;
    }
    initSegTree(o<<1, s, m);
    initSegTree((o<<1)+1, m+1, e);
    Min[o] = min(Min[o<<1], Min[(o<<1)+1]);
    Max[o] = max(Max[o<<1], Max[(o<<1)+1]);
}


int queMin(int o, int s, int e, int l, int r){
    int m = (s+e)>>1, t = INF;

    if(l<=s && r>=e) return Min[o];
    if(l<=m) t = min(t, queMin(o<<1, s, m, l, r));
    if(r>m) t = min(t, queMin((o<<1)+1, m+1, e, l, r));
    return t;
}

int queMax(int o, int s, int e, int l, int r){
    int m = (s+e)>>1, t = 0;

    if(l<=s && r>=e) return Max[o];
    if(l<=m) t = max(t, queMax(o<<1, s, m, l, r));
    if(r>m) t = max(t, queMax((o<<1)+1, m+1, e, l, r));
    return t;
}


