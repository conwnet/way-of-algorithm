#include <stdio.h>
#include <map>

using namespace std;

struct ADT {
        int a, b, c, d, e, f;

        bool operator < (const ADT &B) const
        {
                if(B.a<a && B.b<b && B.c<c && B.d<d && B.e<e && B.f<f)
                        return 1;
                return 0;
        }
};

int main()
{
        map<ADT, int> mp;
        int i, N;
        ADT tmp;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%d%d%d%d%d%d", &tmp.a, &tmp.b, &tmp.c, &tmp.d, &tmp.e, &tmp.f);
                mp[tmp] ++;
        }
        if(mp.size()<N) puts("Twin snowflakes found.");
        else puts("No two snowflakes are alike.");

        return 0;
}
