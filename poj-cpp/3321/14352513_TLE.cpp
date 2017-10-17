#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

vector<int> G[100005];
int N, Q, sum[100005], val[100005], p[100005];

void init();
void change(int x);

int main()
{
        int i, u, v, t;
        char cmd[5];
        queue<int> que;

        scanf("%d", &N);
        for(i=1; i<N; i++) {
                scanf("%d%d", &u, &v);
                G[u].push_back(v);
                G[v].push_back(u);
        }
        memset(p, 0, sizeof(p));
        que.push(1);
        while(!que.empty()) {
                int top = que.front(); que.pop();
                for(i=0; i<G[top].size(); i++) {
                        if(G[top][i] != p[top]) {
                                p[G[top][i]] = top;
                                que.push(G[top][i]);
                        }
                }
        }
        ///for(i=1; i<=N; i++) printf("%d==", p[i]);
        init();
        scanf("%d", &Q);
        while(Q--) {
                scanf("%s%d", cmd, &t);
                if(cmd[0]=='C') {
                        change(t);
                } else {
                        printf("%d\n", sum[t]);
                }
        }


        return 0;
}

void init()
{
        int i;

        for(i=1; i<=N; i++) val[i] = 1;
        memset(sum, 0, sizeof(sum));
        for(i=1; i<=N; i++) {
                int t = i;
                while(t!=0) {
                        sum[t]++;
                        t = p[t];
                }
        }
}

void change(int x)
{
        if(val[x]==1) {
                val[x] = 0;
                int t = x;
                while(t!=0) {
                        sum[t]--;
                        t = p[t];
                }
        } else {
                val[x] = 1;
                int t = x;
                while(t!=0) {
                        sum[t]++;
                        t = p[t];
                }
        }
}
