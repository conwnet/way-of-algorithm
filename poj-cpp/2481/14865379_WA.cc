#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1e5+1;
int bit[maxn], N, M, ln[maxn], rn[maxn], ra[maxn], cnt[maxn], ans[maxn];

int cmp(int a, int b)
{
        if(rn[a]==rn[b]) return ln[a] < ln[b];
        return rn[a] < rn[b];
}

int lowbit(int x)
{
        return x & -x;
}

void Add(int pos, int n)
{
        while(pos<=M) {
                bit[pos] += n;
                pos += lowbit(pos);
        }
}

int Sum(int pos)
{
        int s = 0;
        while(pos>0) {
                s += bit[pos];
                pos -= lowbit(pos);
        }
        return s;
}

int main()
{
        M = maxn;
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++)
                        scanf("%d%d", &ln[i], &rn[i]);
                for(int i=0; i<N; i++)
                        ra[i] = i;
                sort(ra, ra+N, cmp);
                memset(cnt, 0, sizeof(cnt));
                for(int i=N-2; i>=0; i--) {
                        int r = ra[i];
                        if(ln[r]==ln[r+1] && rn[r]==rn[r+1])
                                cnt[r] = cnt[r+1]+1;
                }
                memset(ans, 0, sizeof(ans));
                memset(bit, 0, sizeof(bit));
                for(int i=N-1; i>=0; i--) {
                        int r = ra[i];
                        ans[r] = Sum(ln[r]+1) - cnt[r];
                        Add(ln[r]+1, 1);
                }
                printf("%d", ans[0]);
                for(int i=1; i<N; i++)
                        printf(" %d", ans[i]);
                printf("\n");
        }

        return 0;
}




