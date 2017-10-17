#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100005;
const int maxN = 1299710;

int prime[maxn];
int vst[maxN];

int get_prime()
{
        int t = (int)sqrt(maxN)+0.5;
        memset(vst, 0, sizeof(vst));
        for(int i=2; i<=t; i++) {
                if(!vst[i]) {
                        for(int j=i*i; j<maxN; j+=i)
                                vst[j] = 1;
                }
        }
        int cnt = 0;
        for(int i=2; i<maxN; i++) {
                if(!vst[i]) prime[cnt++] = i;
        }
        return cnt;
}

int gap[maxn];

int main()
{
        int cnt = get_prime();
        int N;

        for(int i=1; i<cnt; i++)
                gap[i] = prime[i]-prime[i-1];
        while(scanf("%d", &N) && N) {
                int t = lower_bound(prime, prime+cnt, N) - prime;
                if(N==prime[t]) printf("0\n");
                else printf("%d\n", gap[t]);
        }

        return 0;
}
