#include <stdio.h>
#include <math.h>

const int maxn = 10005;
const int INF = 0x3f3f3f3f;
int N, K;
double len[maxn];

int is_ok(double d)
{
        int cnt = 0;
        for(int i=0; i<N; i++)
                cnt += floor(len[i]/d);
        return cnt >= K;
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
                scanf("%lf", &len[i]);
        double l = 0; double r = INF;
        while(r-l>0.0001) {
                double m = (l+r) / 2;
                if(is_ok(m)) l = m;
                else r = m;
        }
        printf("%.2f\n", l);

        return 0;
}
