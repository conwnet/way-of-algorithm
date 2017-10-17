#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int ans[1<<15];
int main()
{
        int fact[100], n;
        fact[0] = 1;
        for(int i=1; i<15; i++)
                fact[i] = i*fact[i-1];
        memset(ans, 0x3f, sizeof(0x3f));
        for(int s=0; s<1<<15; s++) {
                int ss = 0;
                for(int i=0; i<15; i++)
                        if(1<<i & s) ss += fact[i-1];
                ans[s] = ss;
        }
        sort(ans, ans+(1<<15));
        while(scanf("%d", &n) && n>=0) {
                int ok = 0;
                if(*lower_bound(ans, ans+(1<<15), n)==n) ok = 1;
                if(ok) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
