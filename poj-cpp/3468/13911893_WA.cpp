#include <stdio.h>
#include <string.h>

long long arr[200000], Sum[300000], addv[300000], _sum, c;
int N, Q, a, b;

void initSum(int o, int L, int R);
void maintain(int o, int L, int R);
void update(int o, int L, int R);
void query(int o, int L, int R, long long add);

int main(){
    char Cmd[10];
    int i;

    scanf("%d%d", &N, &Q);
    for(i=1; i<=N; i++) scanf("%d", &arr[i]);
    initSum(1, 1, N);
    memset(addv, 0, sizeof(addv));
    while(Q--){
        scanf("%s", Cmd);
        if(Cmd[0] == 'Q'){
            scanf("%d%d", &a, &b);
            _sum = 0;
            query(1, 1, N, 0);
            printf("%lld\n", _sum);
        }
        else{
            scanf("%d%d%lld", &a, &b, &c);
            update(1, 1, N);
        }
    }

    return 0;
}

void initSum(int o, int L, int R){
    if(L==R) Sum[o] = arr[L];
    else{
        int M = (L+R)/2;
        initSum(o*2, L, M);
        initSum(o*2+1, M+1, R);
        Sum[o] = Sum[o*2]+Sum[o*2+1];
    }
}

void maintain(int o, int L, int R){
    if(R>L){
        Sum[o] = Sum[o*2]+Sum[o*2+1];
    }
   // Sum[o] += addv[o]*(R-L+1);
}

void update(int o, int L, int R){
    if(a<=L && b>=R){
        Sum[o] += c*(R-L+1);
        addv[o] += c;
        return ;
    }
    else{
        int M = (L+R)/2;
        if(a<=M) update(o*2, L, M);
        if(b>M) update(o*2+1, M+1, R);
    }
    maintain(o, L, R);
}

void query(int o, int L, int R, long long add){
    if(a<=L && b>=R){
        _sum += Sum[o] + add*(R-L+1);
    }
    else{
        int M = (L+R)/2;
        if(a<=M) query(o*2, L, M, add+addv[o]);
        if(b>M) query(o*2+1, M+1, R, add+addv[o]);
    }
}