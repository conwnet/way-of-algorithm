#include <stdio.h>
#include <string.h>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> P;
const int maxv = 2001;

char dis[maxv][maxv];
char str[maxv][10];
bool vst[maxv];
char minv[maxv];
int N;

int prim()
{
        int s = 0, ans = 0;
        priority_queue<P, vector<P>, greater<P> > pq;
        memset(minv, 0x3f, sizeof(minv));
        memset(vst, 0, sizeof(vst));
        minv[s] = 0;
        pq.push(P(0, s));
        while(!pq.empty()) {
                P tmp = pq.top();
                pq.pop();
                if(vst[tmp.second])
                        continue;
                vst[tmp.second] = 1;
                ans += tmp.first;
                for(int i=0; i<N; i++) {
                        if(!vst[i]) {
                                pq.push(P(dis[tmp.second][i], i));
                                //printf("------ %d\n", dis[tmp.second][i]);
                        }
                }
        }
        return ans;
}

int main()
{
        while(scanf("%d", &N) && N) {
                for(int i=0; i<N; i++) {
                        scanf("%s", str[i]);
                }
                for(int i=1; i<N; i++) {
                        for(int j=0; j<i; j++) {
                                int tmp = 0;
                                for(int k=0; k<7; k++)
                                        if(str[i][k] != str[j][k])
                                                tmp++;
                                dis[i][j] = dis[j][i] = tmp;
                        }
                }
                printf("The highest possible quality is 1/%d.\n", prim());
        }

        return 0;
}
