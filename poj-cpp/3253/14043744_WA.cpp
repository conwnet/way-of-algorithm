#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int arr[30000], N, i, sum, rzt;

        scanf("%d", &N);
        sum = 0;
        for(i=0; i<N; i++) {
                scanf("%d", &arr[i]);
                sum += arr[i];
        }
        rzt = sum;
        sort(arr, arr+N);
        for(i=N-1; i>1; i--) rzt += (sum-=arr[i]);
        printf("%d\n", rzt);

        return 0;
}