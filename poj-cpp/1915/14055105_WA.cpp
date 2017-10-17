#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int v[305][305], T, N, sx, sy, ex, ey;

struct ADT {
        int x;
        int y;

        ADT(int a, int b):x(a), y(b){}
};

int main()
{
        queue<ADT> que;

        scanf("%d", &T);
        while(T--) {
                memset(v, 0, sizeof(v));
                scanf("%d", &N);
                scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
                ADT t(sx, sy);
                que.push(t);
                while(!que.empty()) {

                        t = que.front();
                        if(t.x==ex && t.y== ey) break;

                        que.pop();

                        if(t.x-2>=0 && t.y-1>=0 && !v[t.x-2][t.y-1]) { que.push(ADT(t.x-2, t.y-1)); v[t.x-2][t.y-1] = v[t.x][t.y]+1;}
                        if(t.x-2>=0 && t.y+1<N && !v[t.x-2][t.y+1]) { que.push(ADT(t.x-2, t.y+1)); v[t.x-2][t.y+1] = v[t.x][t.y]+1;}
                        if(t.x+2<N && t.y-1>=0 && !v[t.x+2][t.y-1]) { que.push(ADT(t.x+2, t.y-1)); v[t.x+2][t.y-1] = v[t.x][t.y]+1;}
                        if(t.x+2<N && t.y+1<N && !v[t.x+2][t.y+1]) { que.push(ADT(t.x+2, t.y+1)); v[t.x+2][t.y+1] = v[t.x][t.y]+1;}
                        if(t.x-1>=0 && t.y-2>=0 && !v[t.x-1][t.y-2]) { que.push(ADT(t.x-1, t.y-2)); v[t.x-1][t.y-2] = v[t.x][t.y]+1;}
                        if(t.x-1>=0 && t.y+2<N && !v[t.x-1][t.y+2]) { que.push(ADT(t.x-1, t.y+2)); v[t.x-1][t.y+2] = v[t.x][t.y]+1;}
                        if(t.x+1<N && t.y-2>=0 && !v[t.x+1][t.y-2]) { que.push(ADT(t.x+1, t.y-2)); v[t.x+1][t.y-2] = v[t.x][t.y]+1;}
                        if(t.x+1<N && t.y+2<N && !v[t.x+1][t.y+2]) { que.push(ADT(t.x+1, t.y+2)); v[t.x+1][t.y+2] = v[t.x][t.y]+1;}

                }
                printf("%d\n", v[ex][ey]);
        }

        return 0;
}
