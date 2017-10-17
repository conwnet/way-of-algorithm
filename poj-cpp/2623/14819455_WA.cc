#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 250005;
int arr[maxn], N;

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr+N);
        if(N&1) {
                printf("%d\n", arr[N/2]);
        } else {
                printf("%g\n", (arr[N/2]+arr[N/2-1])/2.0);
        }

        return 0;
}
