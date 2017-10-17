#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1000010;
int hn[maxn], hp[maxn], hsp[maxn], vst[maxn];

int solve()
{
        for(int i=0; i<maxn; i++)
                hn[i] = i*4+1;
        memset(vst, 0, sizeof(vst));
        for(int i=1; hn[i]<1024; i++) {
                if(vst[hn[i]]) continue;
                for(int j=i; hn[i]*hn[j]<maxn; j++) {
                        vst[hn[i]*hn[j]] = 1;
                }
        }
        int cnt = 0;
        for(int i=1; hn[i]<maxn; i++)
                if(!vst[hn[i]]) hp[cnt++] = hn[i];
        memset(vst, 0, sizeof(vst));
        for(int i=0; hp[i]<1024; i++) {
                for(int j=i; hp[i]*hp[j]<maxn; j++)
                        vst[hp[i]*hp[j]] = 1;
        }
        cnt = 0;
        for(int i=0; i<maxn; i++)
                if(vst[i]) hsp[cnt++] = i;
        return cnt;
}

int main()
{
        int N;
        int n = solve();
        while(scanf("%d", &N) && N) {
                printf("%d %d\n", N, upper_bound(hsp, hsp+n, N)-hsp);
        }

        return 0;
}
