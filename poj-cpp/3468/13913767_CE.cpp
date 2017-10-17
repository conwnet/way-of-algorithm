#include <stdio.h>
#include <string.h>

long long arr[200000], Sum[300000], addv[300000], _sum, c;
long long N, Q, a, b;

void initSum(long long o, long long L, long long R);
void update(long long o, long long L, long long R);
void query(long long o, long long L, long long R, long long add);

int main(){
    char Cmd[10];
    int i;

    scanf("%lld%lld", &N, &Q);
    for(i=1; i<=N; i++) scanf("%lld", &arr[i]);
    initSum(1, 1, N);
    memset(addv, 0, sizeof(addv));
    while(Q--){
        scanf("%s", Cmd);
        if(Cmd[0] == 'Q'){
            scanf("%lld%lld", &a, &b);
            _sum = 0;
            query(1, 1, N, 0);
            printf("%lld\n", _sum);
        }
        else{
            scanf("%lld%lld%lld", &a, &b, &c);
            update(1, 1, N);
        }
    }

    return 0;
}

void initSum(long long o, long long L, long long R){
    if(L==R) Sum[o] = arr[L];
    else{
        long long M = (L+R)/2;
        initSum(o*2, L, M);
        initSum(o*2+1, M+1, R);
        Sum[o] = Sum[o*2]+Sum[o*2+1];
    }
}

void update(long long o, long long L, long long R){
    if(a<=L && b>=R){
        Sum[o] += c*(R-L+1);
        addv[o] += c;
        return ;
    }
    else{
        long long M = (L+R)/2;
        if(a<=M) update(o*2, L, M);
        if(b>M) update(o*2+1, M+1, R);
    }
    Sum[o] = Sum[o*2]+Sum[o*2+1]+(R-L+1)*addv[o];
}

void query(long long o, long long L, long long R, long long add){
    if(a<=L && b>=R){
        _sum += Sum[o] + add*(R-L+1);
    }
    else{
        long long M = (L+R)/2;
        if(a<=M) query(o*2, L, M, add+addv[o]);
        if(b>M) query(o*2+1, M+1, R, add+addv[o]);
    }
}