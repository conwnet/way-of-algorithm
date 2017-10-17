#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int N, L, A, B;
int cow[1000010];
int dp[1000010];

typedef pair<int, int> P;

priority_queue<P, vector<P>, greater<P> > pq;

int main()
{
        int s, e;
        scanf("%d%d%d%d", &N, &L, &A, &B);
        memset(cow, 0, sizeof(cow));
        for(int i=0; i<N; i++) {
                scanf("%d%d", &s, &e);
                cow[s+1] += 1;
                cow[e] -= 1;
        }
        if(L&1) {
                printf("-1\n");
                return 0;
        }
        for(int i=1; i<=L; i++) {
                cow[i] += cow[i-1];
        }
        for(int i=0; i<1000010; i++)
                dp[i] = 1<<30;
        dp[0] = 1;
        for(int i = A*2; i<=B*2; i+=2) {
                if(!cow[i]) {
                        dp[i] = 1;
                }
                pq.push(P(dp[i-A*2], i-A*2));
        }
        for(int i=B*2+2; i<=L; i+=2) {
                pq.push(P(dp[i-A*2], i-A*2));
                if(!cow[i]) {

                        P top;
                        while(!pq.empty()) {
                                top = pq.top();
                                if(top.second<i-B*2);
                                else break;
                                pq.pop();
                        }
                        dp[i] = top.first + 1;
                }

        }
        if(dp[L]<(1<<30)) printf("%d\n", dp[L]);
        else printf("-1\n");

        return 0;
}
