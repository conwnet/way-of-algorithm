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
                        int mi = 0x3f3f3f3f, ans, l, r;
                        for(int i=0; i<= N; i++) {
                                int tmp = arr[i].first;
                                int j = upper_bound(arr+i, arr+N+1, P(tmp+K, 0)) - arr;
                                if(j==i) continue;
                                if(j-1!=i && abs(arr[j-1].first-arr[i].first - K) < mi) {
                                        mi = abs(arr[j-1].first-arr[i].first - K);
                                        ans = arr[j-1].first-arr[i].first;
                                        l = arr[i].second; r = arr[j-1].second;
                                }
                                if(j<=N && abs(arr[j].first-arr[i].first - K) < mi) {
                                        mi = abs(arr[j].first-arr[i].first - K);
                                        ans = arr[j].first-arr[i].first;
                                        l = arr[i].second; r = arr[j].second;
                                }
                        }
                        if(l > r) swap(l, r);
                        printf("%d %d %d\n", ans, l+1, r);
                }
        }

        return 0;
}