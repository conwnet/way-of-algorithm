#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 10005;
const int INF = 0x3f3f3f3f;
int N, K;
double len[maxn];

int is_ok(double d)
{
        int cnt = 0;
        for(int i=0; i<N; i++)
                cnt += (int)floor(len[i]/d);
        return cnt >= K;
}

int main()
{
        scanf("%d%d", &N, &K);
        double maxl = 0;
        for(int i=0; i<N; i++) {
                scanf("%lf", &len[i]);
                maxl = max(len[i], maxl);
        }
        double l = 0; double r = 100001;
        while(r-l>1e-8) {
                double m = (l+r) / 2;
                if(is_ok(m)) l = m;
                else r = m;
        }
        if((int)(r*1000)%10 >= 5) r -= 0.005;
        printf("%.2f\n", r);

        return 0;
}
