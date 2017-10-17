#include <stdio.h>

int main()
{
        int N, i;

        while(~scanf("%d", &N)) {
                for(i=0; 1<<i<N; i++)
                        if(N&1<<i) break;
                if(1<<i<N) printf("NO\n");
                else printf("YES\n");
        }

        return 0;
}
