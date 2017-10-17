#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
        int T;
        long long n;

        scanf("%d", &T);
        while(T--) {
                scanf("%lld", &n);
                int i;
                for(i=0; i<32; i++)
                        if(n & (1<<i)) break;
                printf("%lld %lld\n", n-(1<<i)+1, n+(1<<i)-1);
        }

        return 0;
}

