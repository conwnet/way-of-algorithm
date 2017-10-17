#include <stdio.h>
#include <string.h>

int N, arr[6000], f[6000];

int main()
{
        int i, j, k, m, sum, res, ans, K;
        char str[10];

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%s", str);
                if(str[0]=='B') arr[i] = 0;
                else arr[i] = 1;
        }
        ans = 9999999;
        for(k=N; k>0; k--) {
                sum = res = 0;
                int ok = 1;
                memset(f, 0, sizeof(f));
                for(i=0; i+k<=N; i++) {
                        if(i-k>=0) sum -= f[i-k];
                        if((arr[i]+sum)%2==0) {
                                f[i] = 1;
                                sum += f[i];
                                res++;
                        }
                }
                for(; i<N; i++) {
                        if(i-k>=0) sum -= f[i-k];
                        if((arr[i]+sum)%2==0) {
                                ok = 0; break;
                        }
                }

                if(ok) {
                        if(res<ans) {
                                ans = res;
                                K = k;
                        }
                }
        }
        printf("%d %d\n", K, ans);


        return 0;
}
/**<

0 0 1 0 1 0 0
1 1 0 1 1 0 0
 */

