#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char mapp[110][110], tmp[110][110];
int cost[110][110];

struct Point{
        int y, x;
        Point(int a, int b):y(a), x(b){}
};

Point t(0, 0);

int main()
{
        queue<Point> q;
        int i, j, k, l, cnt, mins, fy, fx;

        while(~scanf("%d%d", &N, &M)) {
                if(N==0 && M==0) break;
                memset(mapp, 0, sizeof(mapp));
                getchar();
                for(i=1; i<=N; i++) {
                        for(j=1; j<=M; j++) {
                                scanf("%c", &mapp[i][j]);
                        }
                        getchar();
                }
                while(!q.empty()) q.pop();
                cnt = 0;
                for(i=1; i<=N; i++) {
                        for(j=1; j<=M; j++) {
                                if(mapp[i][j]=='m') {
                                        memcpy(tmp, mapp, sizeof(mapp));
                                        memset(cost, 0, sizeof(cost));
                                        q.push(Point(i, j));
                                        tmp[i][j] = 0;
                                        while(!q.empty()) {
                                                t = q.front(); q.pop();
                                                if(tmp[t.y][t.x+1]) { q.push(Point(t.y, t.x+1)); cost[t.y][t.x+1]=cost[t.y][t.x]+1; tmp[t.y][t.x+1]=0; }
                                                if(tmp[t.y][t.x-1]) { q.push(Point(t.y, t.x-1)); cost[t.y][t.x-1]=cost[t.y][t.x]+1; tmp[t.y][t.x-1]=0; }
                                                if(tmp[t.y+1][t.x]) { q.push(Point(t.y+1, t.x)); cost[t.y+1][t.x]=cost[t.y][t.x]+1; tmp[t.y+1][t.x]=0; }
                                                if(tmp[t.y-1][t.x]) { q.push(Point(t.y-1, t.x)); cost[t.y-1][t.x]=cost[t.y][t.x]+1; tmp[t.y-1][t.x]=0; }
                                        }
                                        mins = 999999;
                                        for(k=1; k<=N; k++) {
                                                for(l=1; l<=M; l++) {
                                                        if(mapp[k][l]=='H' && cost[k][l]<mins) { mins=cost[k][l]; fy=k; fx=l; }
                                                }
                                        }
                                        cnt += mins;
                                        mapp[fy][fx] = '.';
                                }
                        }
                }
                printf("%d\n", cnt);
        }

        return 0;
}
