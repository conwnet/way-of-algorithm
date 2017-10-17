#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 100010;
typedef pair<int, int> P;
P arr[maxn];
int N, Q, K;

int main()
{
        while(~scanf("%d%d", &N, &Q)) {
                if(!N && !Q) break;
                for(int i=1; i<=N; i++) {
                        scanf("%d", &arr[i].first);
                        arr[i].second = i;
                }
                arr[0].first = arr[0].second = 0;
                for(int i=1; i<=N; i++)
                        arr[i].first += arr[i-1].first;
                sort(arr, arr+N+1);
                while(Q--) {
                        scanf("%d", &K);
                        int s = 0, e = 1, mi = 0x3f3f3f3f, ans, l, r;
                        for(; s<=N; s++) {
                                for(; e<=N; e++) {
                                        //if(s==e) continue;
                                        int sum = arr[e].first - arr[s].first;
                                        if(abs(sum-K) < mi) {
                                                mi = abs(sum-K);
                                                ans = sum;
                                                l = arr[s].second;
                                                r = arr[e].second;
                                        }
                                        if(sum > K) break;
                                }
                        }
                        if(l > r) swap(l, r);
                        printf("%d %d %d\n", ans, l+1, r);
                }
        }

        return 0;
}
