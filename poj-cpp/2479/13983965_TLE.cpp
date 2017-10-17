#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
        int arr[60000], sum[60000], nCase, s1, s2, sum1, sum2, rzt, i, j, k, n;

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
                rzt = -99999999;
                for(i=1; i<n; i++){
                        if(arr[i]>0) continue;
                        sum1 = sum2 = -99999999;
                        s1 = s2 = 99999999;
                        for(j=0; j<i; j++){
                                s1 = min(s1, sum[j]);
                                sum1 = max(sum1, sum[j]-s1);
                        }
                        for(k=i; k<n; k++){
                                s2 = min(s2, sum[k]);
                                sum2 = max(sum2, sum[k]-s2);
                        }
                        rzt = max(rzt, sum1+sum2);
                }
                printf("%d\n", rzt);
        }

        return 0;
}
