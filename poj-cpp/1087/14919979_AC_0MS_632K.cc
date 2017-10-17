#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> Map;
int n, N, M, K;
char s1[30], s2[30];

const int maxn = 512;
const int INF = 0x3f3f3f3f;
struct Edge {
        int to, cap, next;
} edge[maxn*maxn];
int fir[maxn], ec, num;
void add_edge(int u, int v, int w)
{
        edge[ec] = (Edge){v, w, fir[u]}; fir[u] = ec++;
        edge[ec] = (Edge){u, 0, fir[v]}; fir[v] = ec++;
}

int vst[maxn];
int dfs(int u, int to, int f)
{
        if(u==to) return f;
        vst[u] = 1;
        for(int i=fir[u]; i!=-1; i=edge[i].next) {
                Edge &e = edge[i];
                if(vst[e.to] || 0==e.cap) continue;
                int d = dfs(e.to, to, min(e.cap, f));
                if(d>0) {
                        e.cap -= d;
                        edge[i^1].cap += d;
                        return d;
                }
        }
        return 0;
}

int max_flow(int s, int t)
{
        int res = 0;
        while(1) {
                memset(vst, 0, sizeof(vst));
                int f =  dfs(s, t, INF);
                if(0==f) return res;
                res += f;
        }
}

int main()
{
        int u, v, w;
        memset(fir, -1, sizeof(fir));
        ec = 0; num = 0;
        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%s", s1);
                Map[s1] = ++num;
                add_edge(0, num, 1);
               // printf("%d %d\n", 0, num);
        }
        scanf("%d", &M);
        for(int i=0; i<M; i++) {
                scanf("%s%s", s1, s2);
                if(0==Map[s2]) Map[s2] = ++num;
                add_edge(Map[s2], 511, 1);
               // printf("%d %d\n", Map[s2], 127);
        }
        scanf("%d", &K);
        for(int i=0; i<K; i++) {
                scanf("%s%s", s1, s2);
                if(0==Map[s1]) Map[s1] = ++num;
                if(0==Map[s2]) Map[s2] = ++num;
                add_edge(Map[s2], Map[s1], INF);
               // printf("%d %d\n", Map[s2], Map[s1]);
        }
        printf("%d\n", M-max_flow(0, 511));

        return 0;
}
