#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110000], N, M, T;

int main()
{
        int i, j, l, t;

        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &N, &M);
                arr[0] = 0;
                for(i=1; i<=N; i++) scanf("%d", &arr[i]);
                for(i=1; i<=N; i++) arr[i] += arr[i-1];
                for(i=0, l=999999; i<N; i++) {
                        t = i+l<=N?l:N-i;
                        for(j=i+t; arr[j]-arr[i]>=M; j--)
                                l = min(l, j-i);
                }
                printf("%d\n", l==999?0:l);
        }


        return 0;
}
