#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> Stop;
int N, L, P;
priority_queue<Stop> pq;

int main()
{
        int dis, fuel, ans;

        scanf("%d", &N);
        while(N--) {
                scanf("%d%d", &dis, &fuel);
                pq.push(Stop(dis, fuel));
        }
        scanf("%d%d", &L, &P);
        ans = 0;
        while(!pq.empty()) {
                if(P>=L) break;
                if((L-pq.top().first)<=P) {
                        P += pq.top().second;
                        pq.pop();
                        ans++;
                } else break;
        }
        if(P<L) printf("-1\n");
        else printf("%d\n", ans);

        return 0;
}
