#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> T;

T arr[100001];

int main()
{
        int i, j, n, top, d, N;
        long long ans;

        while(scanf("%d", &N) && N) {
                ans = top = 0;
                for(i=0; i<N; i++) {
                        scanf("%d", &n);
                        d = i;
                        while(top && n<arr[top-1].first) {
                                long long t = (long long)(i-arr[top-1].second) * arr[top-1].first;
                                if(t>ans) ans = t;
                                d = arr[top-1].second; top--;
                        }
                        arr[top++] = T(n, i);
                }
                while(top) {
                        long long t = (long long)(i-arr[top-1].second) * arr[top-1].first;
                        if(t>ans) ans = t;
                        d = arr[top-1].second; top--;
                }
                printf("%lld\n", ans);
        }

        return 0;
}
