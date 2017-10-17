#include <stdio.h>

int per[100010], N;

int main()
{
        int i;

        while(scanf("%d", &N) && N) {
                for(i=1; i<=N; i++)
                        scanf("%d", &per[i]);
                for(i=1; i<=N; i++)
                        if(per[per[i]]!=i) break;
                if(i<=N) printf("not ambiguous\n");
                else printf("ambiguous\n");
        }

        return 0;
}
