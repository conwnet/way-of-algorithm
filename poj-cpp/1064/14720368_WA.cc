#include <stdio.h>

const int maxn = 10005;
const int INF = 0x3f3f3f3f;
int N, K;
double len[maxn];

int is_ok(double d)
{
        int cnt = 0;
        for(int i=0; i<N; i++)
                cnt += len[i]/d;
        return cnt >= K;
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
                scanf("%lf", &len[i]);
        double l = 0; double r = INF;
        while(r-l>0.001) {
                double m = (l+r) / 2;
                if(is_ok(m)) l = m;
                else r = m;
        }
        if(l < 0.01) printf("0.00\n");
        else printf("%.2f\n", l);

        return 0;
}
