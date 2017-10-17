#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int T, n, k, i, arr[1050];
        int fact[1050];

        for(fact[1]=1, i=2; i<14; i++) fact[i] = fact[i-1]*i;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &n, &k);
                if(n<14) k %= fact[n];
                for(i=0; i<n; i++) scanf("%d", &arr[i]);
                while(k && next_permutation(arr, arr+n)) k--;
                while(k) {
                        sort(arr, arr+n);
                        while(k && next_permutation(arr, arr+n)) k--;
                }
                for(i=0; i<n-1; i++) printf("%d ", arr[i]);
                printf("%d\n", arr[n-1]);
        }

        return 0;
}
