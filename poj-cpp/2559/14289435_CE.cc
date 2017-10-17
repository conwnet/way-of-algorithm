#include <stdio.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> T;

T arr[100001];
int N;

int main()
{
        int i, j, n, top, cnt;
        long long ans;

        while(scanf("%d", &N) && N) {
                ans = top = 0;
                while(N--) {
                        scanf("%d", &n);
                        cnt = 0;
                        while(top && arr[top-1].first>n) {
                                T t = arr[--top];
                                ans = max(ans, t.first * (t.second+cnt));
                                cnt++;
                        }
                        arr[top++] = T(n, 1+cnt);
                }
                while(top) {
                        T t = arr[--top];
                        ans = max(ans, t.first * (t.second+cnt));
                        cnt++;
                }
                printf("%lld\n", ans);
        }

        return 0;
}
