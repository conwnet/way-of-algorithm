#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

const int maxn = 10010;
int vst[maxn], prime[maxn], cnt;

void sieve()
{
        int sn = sqrt(maxn)+0.5;
        memset(vst, 0, sizeof(vst));
        vst[0] = vst[1] = 1;
        for(int i=2; i<sn; i++) {
                if(vst[i]) continue;
                for(int j=i*i; j<maxn; j+=i)
                        vst[j] = 1;
        }
        cnt = 0;
        for(int i=2; i<maxn; i++)
                if(!vst[i]) prime[cnt++] = i;

}

int main()
{
        int n;
        sieve();
        while(scanf("%d", &n) && n) {
                int ans = 0;
                for(int i=0; prime[i]<=n; i++) {
                        int sum = 0;
                        for(int j=i; sum<n; j++)
                                sum += prime[j];
                        if(sum==n) ans++;
                }
                printf("%d\n", ans);
        }
        return 0;
}
