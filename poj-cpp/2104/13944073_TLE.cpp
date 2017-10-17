#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int arr[200000], tmp[200000], N, i, Q, l, r, k;
    scanf("%d%d", &N, &Q);
    for(i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    while(Q--){
        scanf("%d%d%d", &l, &r, &k);
        for(i=l; i<=r; i++) tmp[i] = arr[i];
        qsort(tmp+l, r-l+1, sizeof(int), cmp);
        printf("%d\n", tmp[l+k-1]);
    }

    return 0;
}
