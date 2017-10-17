#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[80000], d[80000][33]={0}, e[80000][33]={0}, N, Q;

void initRMQmin();
void initRMQmax();
int RMQmin(int L, int R);
int RMQmax(int L, int R);

int main(){
    int i, L, R;

    scanf("%d%d", &N, &Q);
    for(i=0; i<N; i++) scanf("%d", &arr[i]);
    initRMQmin();
    initRMQmax();
    while(Q--){
        scanf("%d%d", &L, &R);
        printf("%d\n", RMQmax(L-1, R-1)-RMQmin(L-1, R-1));
    }

    return 0;
}

void initRMQmin(){
    int i, j;
    for(i=0; i<N; i++) d[i][0] = arr[i];
    for(j=1; (1<<j)<=N; j++){
        for(i=0; i+(1<<j)-1<N; i++){
            d[i][j] = min(d[i][j-1], d[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQmin(int L, int R){
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return min(d[L][k], d[R-(1<<k)+1][k]);
}

void initRMQmax(){
    int i, j;
    for(i=0; i<N; i++) e[i][0] = arr[i];
    for(j=1; (1<<j)<=N; j++){
        for(i=0; i+(1<<j)-1<N; i++){
            e[i][j] = max(e[i][j-1], e[i+(1<<(j-1))][j-1]);
        }
    }
}

int RMQmax(int L, int R){
    int k=0;
    while((1<<(k+1))<=R-L+1) k++;
    return max(e[L][k], e[R-(1<<k)+1][k]);
}

