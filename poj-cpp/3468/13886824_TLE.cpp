#include <stdio.h>

long long C[200000];
int A[200000], N;

long long Sum(int a);
void Change(int x, long long c);
void Init();
int lowbit(int x){return (x)&(-x);}

int main(){
    int i, j, Q, a, b;
    long long c;
    char Cmd[10];

    scanf("%d%d", &N, &Q);
    for(i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }
    Init();
    C[0] = 0;
    while(Q--){
        scanf("%s", Cmd);
        if(Cmd[0]=='Q'){
            scanf("%d%d", &a, &b);
            printf("%lld\n", Sum(b)-Sum(a-1));
        }
        else{
            scanf("%d%d%lld", &a, &b, &c);
            for(i=a; i<=b; i++){
                Change(i, c);
            }
        }
    }

    return 0;
}

void Init(){
    int i, j, e;
    for(i=1; i<=N; i++){
        for(j=i-lowbit(i)+1; j<=i; j++){
            C[i] += A[j];
        }
    }
}

long long Sum(int x){
    int sum = 0;
    while(x>0){
        sum += C[x];
        x -= lowbit(x);
    }
    return sum;
}

void Change(int x, long long c){
    while(x<N){
        C[x] += c;
        x += lowbit(x);
    }
}