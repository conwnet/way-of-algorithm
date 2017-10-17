#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int arr[10], T, N, arr1[10], arr2[10];

int main()
{
        int a, b, i, j, t, ans, n1, n2, n;

        scanf("%d", &T);
        while(T--) {
                for(N=0; ; N++) {
                        scanf("%d", &arr[N]);
                        if(getchar()=='\n') break;
                }
                N++;
                ans = 999999999;
                t = 1<<(N-1);
                for(i=1; i<=t; i++) {
                        for(j=0, n=0; j<N; j++) if(i&(1<<j)) n++;
                        if(n!=N/2) continue;
                        a = b = 0;
                        for(j=0; j<N; j++) {
                                if(i&(1<<j)) arr1[a++] = arr[j];
                                else arr2[b++] = arr[j];
                        }
                        sort(arr1, arr1+a);
                        sort(arr2, arr2+b);
                        do {
                                if(arr1[0]==0 || arr2[0]==0) continue;
                                n1 = n2 = 0;
                                for(j=0; j<a; j++) {
                                        n1 *= 10;
                                        n1 += arr1[j];
                                }
                                for(j=0; j<b; j++) {
                                        n2 *= 10;
                                        n2 += arr2[j];
                                }
                                ans = min(ans, abs(n1-n2));
                        } while(next_permutation(arr1, arr1+a) || next_permutation(arr2, arr2+b));
                }
                printf("%d\n", ans);
        }

        return 0;
}
