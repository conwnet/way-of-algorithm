#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int T, n, k, i, arr[1050];

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &n, &k);
                for(i=0; i<n; i++) scanf("%d", &arr[i]);
                while(k && next_permutation(arr, arr+n)) k--;
                if(k) {
                        sort(arr, arr+n);
                        while(k && next_permutation(arr, arr+n)) k--;
                }
                for(i=0; i<n-1; i++) printf("%d ", arr[i]);
                printf("%d\n", arr[n-1]);
        }

        return 0;
}
