#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 10005;
int arr[maxn], tmp[maxn];

int main()
{
        int T, N;

        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                for(int i=0; i<N; i++) {
                        scanf("%d", &arr[i]);
                        tmp[i] = arr[i];
                }
                int ans = 0;
                sort(tmp, tmp+N);
                for(int i=0; i<N; ) {
                        int r = lower_bound(tmp, tmp+N, arr[i]) - tmp;
                        if(r==i) { i++; continue; }
                        swap(arr[i], arr[r]);
                        ans++;
                }
                printf("%d\n", ans);
        }

        return 0;
}
