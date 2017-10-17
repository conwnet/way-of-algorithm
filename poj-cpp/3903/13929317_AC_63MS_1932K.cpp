#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int num[150000], t[150000], cnt[150000], N, i, j, maxs;

    while(~scanf("%d", &N)){
        for(i=0; i<N; i++){
            scanf("%d", &num[i]);
            t[i+1] = 999999999;
        }
        maxs = 0;
        for(i=0; i<N; i++){
            int k = lower_bound(t+1, t+N+1, num[i])-t;
            cnt[i] = k;
            t[k] = num[i];
            maxs = max(maxs, cnt[i]);
        }
        printf("%d\n", maxs);
    }

    return 0;
}
