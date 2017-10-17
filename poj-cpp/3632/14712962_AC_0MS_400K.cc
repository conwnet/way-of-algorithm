#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[30];

int main()
{
        int T, N;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++)
                        scanf("%d", &arr[i]);
                sort(arr, arr+N);
                int m = (N-1) >> 1;
                int sum = 0;
                sum += arr[m]-arr[0] + arr[N-1]-arr[m];
                printf("%d\n", sum*2);
        }

        return 0;
}
