#include <stdio.h>
#include <queue>

using namespace std;

typedef pair<int, int> Stop;
int N, L, P;
priority_queue<Stop> stop;
priority_queue<int> store;

int main()
{
        int dis, fuel, ans;

        scanf("%d", &N);
        while(N--) {
                scanf("%d%d", &dis, &fuel);
                stop.push(Stop(dis, fuel));
        }
        scanf("%d%d", &L, &P);
        ans = 0;
        while(!stop.empty()) {
                if(P>=L) break;
                if((L-stop.top().first)<=P) {
                        store.push(stop.top().second);
                        stop.pop();
                } else {
                        if(store.empty()) break;
                        P += store.top();
                        ans++;
                }
        }
        if(P<L) printf("-1\n");
        else printf("%d\n", ans);

        return 0;
}
