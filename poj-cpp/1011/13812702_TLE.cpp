#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int low, high, n, stk[64], use[64], sum, ok;

int dfs(int a, int b);
void Search(int a);

int cmp(int a, int b){
    return a>b;
}

int main(){
    int i;

    while(scanf("%d", &n)!=EOF){
        if(n==0) break;
        memset(use, 0, 256);
        high = 0;
        for(i=0; i<n; i++){
            scanf("%d", &stk[i]);
            high += stk[i];
        }
        sort(stk, stk+n, cmp);
        low = stk[0];
        for(i=low; i<=high; i++){
            sum = 0;
            ok = 0;
            Search(i);
            if(ok) break;
        }
        printf("%d\n", i);
    }

    return 0;
}

void Search(int a){
    if(high%a){
        ok = 0;
        return ;
    }
    dfs(a, 0);
}

int dfs(int a, int b){
    if(b==n){
        ok = 1;
        return 1;
    }
    else{
        for(int i=0; i<n; i++){
            if(use[i]==1) continue;
            if(sum>a) return 0;
            if(sum==a) sum = 0;
            sum += stk[i];
            use[i] = 1;
            dfs(a, b+1);
            use[i] = 0;
            sum -= stk[i];
        }
    }
    return 0;
}

