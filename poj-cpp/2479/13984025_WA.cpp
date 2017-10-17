#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int arr[60000], sum[60000], l[60000], r[60000], nCase, sum1, rzt, i, n, maxs;

        scanf("%d", &nCase);
        while(nCase--){
                scanf("%d", &n);
                if(n>0){
                        scanf("%d", &arr[0]);
                        sum[0] = arr[0];
                }
                for(i=1; i<n; i++){
                        scanf("%d", &arr[i]);
                        sum[i] = arr[i]+sum[i-1];
                }
                sum1 = 99999999;
                maxs = arr[0];
                l[0] = arr[0];
                for(i=1; i<n; i++){
                        sum1 = min(sum1, sum[i-1]);
                        maxs = max(maxs, sum[i]-sum1);
                        l[i] = maxs;
                }

                for(i=n-2, sum[n-1]=arr[n-1]; i>=0; i--){
                        sum[i] = arr[i]+sum[i+1];
                }
                sum1 = 99999999;
                maxs = arr[n-1];
                r[n-1] = arr[n-1];
                for(i=n-2; i>=0; i--){
                        sum1 = min(sum1, sum[i+1]);
                        maxs = max(maxs, sum[i]-sum1);
                        r[i] = maxs;
                }

                rzt = -99999999;
                for(i=0; i<n-1; i++){
                        rzt = max(rzt, l[i]+r[i+1]);
                }

                printf("%d\n", rzt);
        }

        return 0;
}
