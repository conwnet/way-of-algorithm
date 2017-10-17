#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int N, arr[2000], tmp[2000], i, j, t, maxs=0;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<N; i++){
        for(t=0, j=0; j<i; j++){
            if(arr[j]<arr[i]){
                t = max(t, tmp[j]);
            }
        }
        tmp[i] = max(0, t)+1;
        maxs = max(maxs, tmp[i]);
    }
    printf("%d\n", maxs);

    return 0;
}
