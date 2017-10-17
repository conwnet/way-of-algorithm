#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 210;
int fir[maxn], to[maxn*maxn], next[maxn*maxn], ec;
int ind[maxn], arr[maxn], vst[maxn], cnt, N, M;

int bfs()
{
        queue<int> que;
        memset(vst, 0, sizeof(vst));
        for(int i=1; i<=N; i++)
                if(!ind[i]) { que.push(i); break; }
        while(!que.empty()) {
                while(!que.empty()) {
                        int u = que.front(); que.pop();
                        arr[cnt++] = u; vst[u] = 1;
                        for(int i=fir[u]; i!=-1; i=next[i])
                                ind[to[i]]--;
                }
                for(int i=1; i<=N; i++)
                        if(!vst[i] && !ind[i]) { que.push(i); break; }
        }
}

int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                memset(ind, 0, sizeof(ind));
                scanf("%d%d", &N, &M);
                for(int i=0; i<M; i++) {
                        scanf("%d%d", &u, &v);
                        to[ec] = v; next[ec] = fir[u];
                        fir[u] = ec++; ind[v]++;
                }
                cnt = 0;
                bfs();
                if(cnt<N) printf("-1\n");
                else {
                        printf("%d", arr[0]);
                        for(int i=1; i<cnt; i++)
                                printf(" %d", arr[i]);
                        printf("\n");
                }
        }

        return 0;
}
