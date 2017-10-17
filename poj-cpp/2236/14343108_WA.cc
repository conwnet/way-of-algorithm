#include <stdio.h>
#include <math.h>

struct Dot {
        int x, y;
        int f;
        double dis(Dot B) {
                return sqrt((B.x-x) * (B.x-x) + (B.y-y) * (B.y-y));
        }
};

Dot dot[1100];
int p[1100], d, N;

int findp(int x)
{
        return x==p[x] ? x : p[x]=findp(p[x]);
}

int main()
{
        int i, m, n;
        char cmd[5];

        scanf("%d%d", &N, &d);
        for(i=1; i<=N; i++) {
                scanf("%d%d", &dot[i].x, &dot[i].y);
                dot[i].f = 0;
        }
        for(i=0; i<=N; i++) p[i] = i;
        while(~scanf("%s", cmd)) {
                if(cmd[0]=='O') {
                        scanf("%d", &n);
                        dot[n].f = 1;
                        for(i=1; i<=N; i++) {
                                ///puts("test");
                                if(n!=i && dot[i].f && findp(i)!=n && dot[n].dis(dot[i])<d+0.00001) {
                                        p[i] = n;
                                }
                        }
                } else {
                        scanf("%d%d", &m, &n);
                        int root = findp(n);
                        if(dot[m].f && dot[n].f) {
                                for(i=1; i<=N; i++) {
                                        if(i!=m && dot[i].f && dot[m].dis(dot[i])<d+0.00001) {
                                              ///  printf("%d %d--", findp(i), root);
                                              ///  puts("test");
                                                if(findp(i)==root) break;
                                        }
                                }
                                if(i>N) printf("FAIL\n");
                                else printf("SUCCESS\n");
                        } else printf("FAIL\n");
                }
        }

        return 0;
}
