#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        long long arr[30000], N, i, sum, rzt;

        scanf("%lld", &N);
        sum = 0;
        for(i=0; i<N; i++) {
                scanf("%lld", &arr[i]);
                sum += arr[i];
        }
        rzt = sum;
        sort(arr, arr+N);
        for(i=N-1; i>1; i--) rzt += (sum-=arr[i]);
        printf("%lld\n", rzt);

        return 0;
}
