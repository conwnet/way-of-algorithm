#include <stdio.h>

char str[20][25], N;

int main()
{
        int nCase, s, e, i;

        nCase = 0;
        while(scanf("%d", &N) && N) {
                for(i=0; i<N; i++)
                        scanf("%s", &str[i]);
                printf("SET %d\n", ++nCase);
                for(i=0; i<N; i+=2) printf("%s\n", str[i]);
                if(N&1) N-=2; else N--;
                for( ; N>0; N-=2) printf("%s\n", str[N]);
        }

        return 0;
}
