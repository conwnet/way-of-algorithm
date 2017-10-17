#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

struct Point {
        int y, x;
        Point(int a, int b) {
                y = a;
                x = b;
        }
        Point(){}
};

struct Meteor {
        int y, x, t;
        bool operator < (const Meteor& b) const {
                return t<b.t;
        }
}met[60000];


int maps[310][310], M;

int main()
{
        int i, j, ok = 0;
        queue<Point> q;

        scanf("%d", &M);
        for(i=0; i<M; i++) {
                scanf("%d%d%d", &met[i].y, &met[i].x, &met[i].t);
        }
        sort(met, met+M);
        q.push(Point(0, 0));
        memset(maps, 0, sizeof(maps));
        while(!q.empty()) {
                Point t = q.front(); q.pop();
                int time = maps[t.y][t.x];
                for(i=0; met[i].t<=time; i++) {
                        if(met[i].t==time) {
                                maps[met[i].y][met[i].x] = -1;
                                maps[met[i].y+1][met[i].x] = -1;
                                if(met[i].y-1>=0) maps[met[i].y-1][met[i].x] = -1;
                                maps[met[i].y][met[i].x+1] = -1;
                                if(met[i].x-1>=0) maps[met[i].y][met[i].x-1] = -1;
                                if(i==M-1) {ok=1; break;}
                        }
                }
                if(ok) break;
                /*
                for(i=0; i<7; i++) {
                        for(j=0; j<7; j++) printf("%2d ", maps[i][j]);
                        printf("\n");
                }
                printf("queue:%d\n", q.size());
                printf("\n");
                */
                if(maps[t.y][t.x]!=-1) {
                        if(t.y-1>=0 && maps[t.y-1][t.x]!=-1) q.push(Point(t.y-1, t.x)), maps[t.y-1][t.x] = maps[t.y][t.x]+1;
                        if(t.y+1>=0 && maps[t.y+1][t.x]!=-1) q.push(Point(t.y+1, t.x)), maps[t.y+1][t.x] = maps[t.y][t.x]+1;
                        if(t.x-1>=0 && maps[t.y][t.x-1]!=-1) q.push(Point(t.y, t.x-1)), maps[t.y][t.x-1] = maps[t.y][t.x]+1;
                        if(t.x+1>=0 && maps[t.y][t.x+1]!=-1) q.push(Point(t.y, t.x+1)), maps[t.y][t.x+1] = maps[t.y][t.x]+1;
                }
        }
        int ans = 999999;
        for(i=0; i<305; i++) {
                for(j=0; j<305; j++) {
                        if(maps[i][j]>0) ans = min(ans, maps[i][j]);
                }
        }
        if(ans==999999) printf("%d\n", -1);
        else printf("%d\n", ans);

        return 0;
}


/**<

4
0 0 2
2 1 2
1 1 2
0 3 5

 */
