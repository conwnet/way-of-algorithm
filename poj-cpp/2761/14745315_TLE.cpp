#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100005;
int N, M, K;
int num[maxn];
vector<int> dat[maxn*4];

void build(int L, int R, int o)
{
        if(L==R) dat[o].push_back(num[L]);
        else {
                int M = (L+R)>>1;
                build(L, M, o*2);
                build(M+1, R, o*2+1);
                dat[o].resize(R-L+1);
                merge(dat[o*2].begin(), dat[o*2].end(),
                dat[o*2+1].begin(), dat[o*2+1].end(), dat[o].begin());
        }
}

int _l, _r, _x;
int query(int L, int R, int o)
{
        if(_l<=L && _r>=R) {
                return upper_bound(dat[o].begin(), dat[o].end(), _x) - dat[o].begin();
        }
        int M = (L+R)>>1;
        int a = 0; int b = 0;
        if(_l<=M) a = query(L, M, o*2);
        if(_r>M) b = query(M+1, R, o*2+1);
        return a+b;
}

int main()
{
        scanf("%d%d", &N, &M);
        for(int i=1; i<=N; i++)
                scanf("%d", &num[i]);
        build(1, N, 1);
        sort(num+1, num+1+N);
        while(M--) {
                scanf("%d%d%d", &_l, &_r, &K);
                int l = 1;
                int r = N;
                while(l<r) {
                        int m = (l+r)>>1;
                        _x = num[m];
                        if(query(1, N, 1) < K) l = m+1;
                        else r = m;
                }
                printf("%d\n", num[l]);
        }

        return 0;
}
