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
                        int s = 0, e = 1, mi = 0x3f3f3f3f, ans, fs, fe;
                        for(; s<e && s<=N; s++) {
                                int sum = 0;
                                for(; e<=N; e++) {
                                        //if(arr[s].second > arr[e].second) continue;
                                        sum = arr[e].first - arr[s].first;
                                        if(abs(abs(sum)-K) < mi) {
                                                mi = abs(abs(sum)-K);
                                                ans = abs(sum);
                                                fs = arr[s].second; fe = arr[e].second;
                                        }
                                        if(abs(sum) > K) { e--; break; }
                                }
                        }
                        if(fs > fe) swap(fs, fe);
                        printf("%d %d %d\n", ans, fs+1, fe);
                }
        }

        return 0;
}