#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int arr[110000], tmp[110000], N, i, Q, l, r, k;
    scanf("%d%d", &N, &Q);
    for(i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    while(Q--){
        scanf("%d%d%d", &l, &r, &k);
        for(i=l; i<=r; i++) tmp[i] = arr[i];
        sort(tmp+l, tmp+r);
        printf("%d\n", tmp[l+k-1]);
    }

    return 0;
}
