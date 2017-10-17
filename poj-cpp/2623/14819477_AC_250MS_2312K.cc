#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 250005;
long long arr[maxn], N;

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%lld", &arr[i]);
        sort(arr, arr+N);
        if(N&1) {
                printf("%lld.0\n", arr[N/2]);
        } else {
                long long t = arr[N/2]+arr[N/2-1];
                if(t&1) printf("%.1f\n", t/2.0);
                else printf("%lld.0\n", t/2);
        }

        return 0;
}
