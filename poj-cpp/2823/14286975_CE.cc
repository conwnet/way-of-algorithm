#include <stdio.h>
#include <algorithm>

#define INF 99999999

using namespace std;

int amin[2100000], amax[2100000], arr[1100000], N, k;

void init(int o, int L, int R);
int getMax(int o, int L, int R, int l, int r);
int getMin(int o, int L, int R, int l, int r);

int main(){
    int i;

    scanf("%d%d", &N, &k);
    for(i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    init(1, 1, N);
    int t = N-k+1;
    printf("%d", getMin(1, 1, N, 1, k));
    for(i=2; i<=t; i++){
        printf(" %d", getMin(1, 1, N, i, i+k-1));
    }
    printf("\n%d", getMax(1, 1, N, 1, k));
    for(i=2; i<=t; i++){
        printf(" %d", getMax(1, 1, N, i, i+k-1));
    }

    return 0;
}

void init(int o, int L, int R){
    if(L==R){
        amin[o] = amax[o] = arr[L];
    }
    else{
        int M = (L+R)/2;
        init(o*2, L, M);
        init(o*2+1, M+1, R);
        amax[o] = max(amax[o*2], amax[o*2+1]);
        amin[o] = min(amin[o*2], amin[o*2+1]);
    }
}

int getMax(int o, int L, int R, int l, int r){
    if(l<=L && r>=R){
        return amax[o];
    }
    else{
        int M = (L+R)/2;
        int t1=-INF, t2=-INF;
        if(l<=M) t1 = getMax(o*2, L, M, l, r);
        if(r>M) t2 = getMax(o*2+1, M+1, R, l, r);
        return max(t1, t2);
    }
}

int getMin(int o, int L, int R, int l, int r){
    if(l<=L && r>=R){
        return amin[o];
 #include <stdio.h>

int amin[110000][33], amax[110000][33], N, k;


int min(int a, int b){
    return a<b?a:b;
}
int max(int a, int b){
    return a>b?a:b;
}
void initMin();
void initMax();
int Min(int L, int R);
int Max(int L, int R);

int main(){
    int i, t;

    scanf("%d%d", &N, &k);
    for(i=0; i<N; i++){
        scanf("%d", &amin[i][0]);
        amax[i][0] = amin[i][0];
    }
    initMin();
    initMax();
    t = N-k;
    printf("%d", Min(0, k-1));
    for(i=1; i<=t; i++){
        printf(" %d", Min(i, i+k-1));
    }
    printf("\n%d", Max(0, k-1));
    for(i=1; i<=t; i++){
        printf(" %d", Max(i, i+k-1));
    }

    return 0;
}

void initMin(){
    int i, j;
    for(j=1; (1<<j)<=N; j++){
        for(i=0; i+(1<<j)<=N; i++){
            amin[i][j] = min(amin[i][j-1], amin[i+(1<<j-1)][j-1]);
        }
    }
}

void initMax(){
    int i, j;
    for(j=1; (1<<j)<N; j++){
        for(i=0; i+(1<<j)<=N; i++){
            amax[i][j] = max(amax[i][j-1], amax[i+(1<<j-1)][j-1]);
        }
    }
}

int Min(int L, int R){
    int k=0;
    while((1<<k+1)<=(R-L+1)) k++;
    return min(amin[L][k], amin[R-(1<<k)+1][k]);
}

int Max(int L, int R){
    int k=0;
    while((1<<k+1)<=(R-L+1)) k++;
    return max(amax[L][k], amax[R-(1<<k)+1][k]);
}
   }
    else{
        int M = (L+R)/2;
        int t1=INF, t2=INF;
        if(l<=M) t1 = getMin(o*2, L, M, l, r);
        if(r>M) t2 = getMin(o*2+1, M+1, R, l, r);
        return min(t1, t2);
    }
}