#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1e5+1;
int ra[maxn], ln[maxn], rn[maxn], cnt[maxn], N, M;

int cmp(int a, int b)
{
        if(rn[a]==rn[b]) return ln[a] < ln[b];
        return rn[a] < rn[b];
}

int bit[maxn];
inline int lowbit(int x)
{
        return x & -x;
}

void Add(int pos, int n)
{
        while(pos<=N) {
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
        ///freopen("in.txt", "r", stdin);
        while(scanf("%d", &M) && M) {
                for(int i=0; i<M; i++)
                        scanf("%d%d", &ln[i], &rn[i]);
                for(int i=0; i<M; i++) ra[i] = i;
                sort(ra, ra+M, cmp);
                memset(cnt, 0, sizeof(cnt));
                memset(bit, 0, sizeof(bit));
                N = 1e5;
                for(int i=M-1; i>=0; i--) {
                        int r = ra[i];
                        cnt[r] += Sum(ln[r]+1);
                        Add(ln[r]+1, 1);
                }
                printf("%d", cnt[0]);
                for(int i=1; i<M; i++) printf(" %d", cnt[i]);
                printf("\n");
        }

        return 0;
}
