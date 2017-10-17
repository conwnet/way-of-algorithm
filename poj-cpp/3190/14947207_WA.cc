#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

P cow[50010];
int N, vst[50010];

int main()
{
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%d%d", &cow[i].first, &cow[i].second);
        sort(cow, cow+N);
        memset(vst, 0, sizeof(vst));
        P s = P(0, 0); int t, ans = 0;
        for(int i=0; i<N; i++) {
                if(vst[i]) continue;
                vst[i] = ++ans;
                s.first = cow[i].second;
                while(t=lower_bound(cow, cow+N, s)-cow) {
                        if(t==N) break;
                        vst[t] = ans;
                        s.first = cow[t].second;
                }
        }
        printf("%d\n", ans);
        for(int i=0; i<N; i++) printf("%d\n", vst[i]);

        return 0;
}




