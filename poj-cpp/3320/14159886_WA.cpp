#include <stdio.h>
#include <string.h>

int arr[1100000], N, i, ans, t;

int main()
{
        scanf("%d", &N);
        memset(arr, 0, sizeof(arr));
        ans = 0;
        for(i=0; i<N; i++) {
                scanf("%d", &t);
                if(!arr[t]) {
                        arr[t] = 1;
                        ans++;
                }
        }
        printf("%d\n", ans);

        return 0;
}
