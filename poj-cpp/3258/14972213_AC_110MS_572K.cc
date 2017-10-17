#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int rock[50010], N, L, M;

int judge(int m)
{
        int ret = 0, pre = 0, n;
        for(n=N-1; n>0; n--)
                if(L-rock[n]<m) ret++;
                else break;
        for(int i=0; i<=n; i++) {
                if(rock[i]-pre >= m)
                        pre = rock[i];
                else ret++;
        }
        return ret;
}

int main()
{
        scanf("%d%d%d", &L, &N, &M);
        for(int i=0; i<N; i++)
                scanf("%d", &rock[i]);
        sort(rock, rock+N);
        int l = 0, r = L;
        while(l<r) {
                int m = l+r+1 >> 1;
                if(judge(m)<=M) l = m;
                else r = m-1;
        }
        printf("%d\n", l);

        return 0;
}
