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

