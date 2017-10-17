#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main(){
    int num[2000], cnt[2000], N, i, j, maxs;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &num[i]);
    }
    cnt[0] = 1;
    for(i=0; i<N; i++){
        for(j=0; j<i; j++){
            if(num[j]<num[i]){
                cnt[i] = max(0, cnt[j])+1;
            }
        }
    }
    maxs = 0;
    for(i=0; i<N; i++)
        maxs = max(maxs, cnt[i]);
    printf("%d\n", maxs);

    return 0;
}