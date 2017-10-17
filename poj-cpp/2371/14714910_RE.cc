#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[5005];

int main()
{
        int N, n;
        char str[1024];

        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        sort(arr, arr+N);
        scanf("%s", str);
        scanf("%d", &N);
        while(N--) {
                scanf("%d", &n);
                printf("%d\n", arr[n-1]);
        }

        return 0;
}
