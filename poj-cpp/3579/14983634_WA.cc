#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long ll;
int N, x[100010];

int judge(int m)
{
        ll cnt = 0;
        for(int i=0; i<N; i++) {
                int t = upper_bound(x, x+N, x[i]+m) - x;
                cnt += N-t;
        }
        return cnt >= (ll)N*(N-1)/4;
}

int main()
{
        while(~scanf("%d", &N)) {
                for(int i=0; i<N; i++)
                        scanf("%d", &x[i]);
                int l = 0, r = 1000000000;
                sort(x, x+N);
                while(l<r) {
                        int m = l+r+1 >> 1;
                        if(judge(m)) l = m;
                        else r = m-1;
                }
                printf("%d\n", l);
        }

        return 0;
}
