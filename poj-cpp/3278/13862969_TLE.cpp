#include <cstdio>
#include <cstring>

int N, K, vst[300000];

int dfs(int t, int n);

int main(){
    int s, i, t, mins;

    while(~scanf("%d%d", &N, &K)){
        if(N>=K){
            printf("%d\n", N-K);
            continue;
        }
        mins = N-K;
        s = 0;
        t = N;
        if(t<K){
            s++;
            t *= 2;
        }
        for(; ; s++){
            memset(vst, 0, 1200000);
            if(dfs(N, s)) break;
        }
        printf("%d\n", s);
    }

    return 0;
}

int dfs(int t, int n){
    if(!n){
        if(t==K) return 1;
        else return 0;
    }
    else{
        if(t>0 && !vst[t]){
            vst[t] = 1;
            if(dfs(t-1, n-1)) return 1;
            vst[t] = 0;
        }
        if(t<K && !vst[t]){
            vst[t] = 1;
            if(dfs(t+1, n-1)) return 1;
            vst[t] = 0;
        }
        if(t<K && !vst[t]){
            vst[t] = 1;
            if(dfs(t*2, n-1)) return 1;
            vst[t] = 0;
        }
    }
    return 0;
}