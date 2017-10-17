#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 40010;

int N, arr[maxn], d[maxn];

int main()
{
        int T;
        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++)
                        scanf("%d", &arr[i]);
                memset(d, 0x3f, sizeof(d));
                int ans = 0;
                for(int i=0; i<N; i++) {
                        int t = lower_bound(d, d+N, arr[i]) - d;
                        d[t] = arr[i];
                        if(t > ans) ans = t;
                }
                printf("%d\n", ans+1);

        }

        return 0;
}
