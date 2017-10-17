#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1024], R, N;

int main()
{
        int i, ans;

        while(scanf("%d%d", &R, &N)) {
                if(R==-1 && N==-1) break;
                for(i=0; i<N; i++) scanf("%d", &arr[i]);
                sort(arr, arr+N);
                ans = 0;
                for(i=0; i<N; ) {
                        int t = upper_bound(arr+i, arr+N, *(arr+i)+R) - arr;
                        i = t-1;
                        t = upper_bound(arr+i, arr+N, *(arr+i)+R) - arr;
                        i = t;
                        ans ++;
                }
                printf("%d\n", ans);
        }

        return 0;
}
