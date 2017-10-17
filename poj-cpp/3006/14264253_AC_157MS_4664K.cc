#include <stdio.h>
#include <string.h>
#include <math.h>

int pri[1100000];

void get_prime(int N)
{
        int i, j;

        memset(pri, 0, sizeof(pri));
        pri[0] = pri[1] = 1;
        int n = sqrt(N)+0.5;
        for(i=2; i<=n; i++) {
                if(!pri[i])
                for(j=i*i; j<=N; j+=i)
                        pri[j] = 1;
        }
}

int main()
{
        int a, b, c;

        get_prime(1000000);
        while(scanf("%d%d%d", &a, &b, &c)) {
                if(a==0 && b==0 && c==0) break;
                a -= b;
                while(c) {
                        a += b;
                        if(!pri[a]) c--;
                }
                printf("%d\n", a);
        }

        return 0;
}
