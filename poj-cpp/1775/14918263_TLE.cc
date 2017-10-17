#include <stdio.h>

int main()
{
        int fact[100], n;
        fact[0] = 1;
        for(int i=1; i<15; i++)
                fact[i] = i*fact[i-1];
        while(scanf("%d", &n) && n>=0) {
                int ok = 0;
                for(int s=0; s<1<<15; s++) {
                        int ss = 0;
                        for(int i=0; i<15; i++)
                                if(1<<i & s) ss += fact[i-1];
                        if(ss==n) { ok = 1; break; }
                }
                if(ok) printf("YES\n");
                else printf("NO\n");
        }

        return 0;
}
