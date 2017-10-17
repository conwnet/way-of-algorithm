#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int N, bit[1005];

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

int tmp[1005], arr[1005];
int main()
{
        int T;
        scanf("%d", &T);
        for(int nC=1; nC<=T; nC++) {
                scanf("%d", &N);
                for(int i=0; i<N; i++) {
                        scanf("%d", &arr[i]);
                        tmp[i] = arr[i];
                }
                sort(tmp, tmp+N);
                unique(tmp, tmp+N);
                int ans = 0;
                memset(bit, 0, sizeof(bit));
                for(int i=0; i<N; i++) {
                        int r = lower_bound(tmp, tmp+N, arr[i]) - tmp + 1;
                        ans += i - Sum(r);
                        Add(r, 1);
                }
                printf("Scenario #%d:\n", nC);
                printf("%d\n", ans);
        }
        return 0;
}
