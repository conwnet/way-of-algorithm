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
                for(int i=0; i<N; i++) {
                        scanf("%d", &arr[i].first);
                        arr[i].second = i;
                }
                for(int i=1; i<N; i++)
                        arr[i].first += arr[i-1].first;
                sort(arr, arr+N);
                while(Q--) {
                        scanf("%d", &K);
                        int s = 1, e = 1, mi = 0x3f3f3f3f, ans, fs, fe;
                        for(; s<=e && s<N; s++) {
                                int sum;
                                for(; e<N; e++) {
                                        if(arr[s-1].second > arr[e].second)
                                                        continue;
                                        sum = arr[e].first - arr[s-1].first;
                                        if(abs(sum) > K) break;
                                        if(abs(abs(sum)-K)<mi) {
                                                mi = abs(abs(sum)-K);
                                                ans = abs(sum);
                                                fs = arr[s-1].second+1; fe = arr[e].second;
                                        }
                                }
                                if(e<N && abs(abs(sum)-K)<mi) {
                                        if(arr[s-1].second > arr[e].second)
                                                        continue;
                                        mi = abs(abs(sum)-K);
                                        ans = abs(sum);
                                        fs = arr[s-1].second+1; fe = arr[e].second;
                                }
                        }
                        for(int i=0; i<N; i++) {
                                if(abs(abs(arr[i].first)-K) < mi) {
                                        mi = abs(abs(arr[i].first)-K);
                                        ans = abs(arr[i].first);
                                        fs = 0; fe = arr[i].second;
                                }
                        }
                        if(fs > fe) swap(fs, fe);
                        printf("%d %d %d\n", ans, fs+1, fe+1);
                }
        }

        return 0;
}
