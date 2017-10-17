#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
const int INF = (1<<20)+1;
int len[INF], cnt[INF];

void solve()
{
        len[1] = 0; cnt[1] = 1;
        for(int i=1; i<=INF; i++) {
                for(int k=2; i*k<=INF; k++) {
                        int t = len[i] + 1;
                        if(t > len[i*k]) {
                                len[i*k] = t;
                                cnt[i*k] = cnt[i];
                        } else if(t==len[i*k])
                                cnt[i*k] += cnt[i];
                }
        }
}

int main()
{
        int n;
        solve();
        while(~scanf("%d", &n)) {
                printf("%d %d\n", len[n], cnt[n]);
        }

        return 0;
}
