#include <stdio.h>
#include <string.h>

char ss[128], str[1024][18];
int val[1024];

int main()
{
        int N, M;
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; i++) {
                scanf("%s%d", str[i], &val[i]);
        }
        while(M--) {
                int ans = 0;
                while(scanf("%s", ss)) {
                        if(ss[0]=='.') break;
                        for(int i=0; i<N; i++) {
                                if(strcmp(ss, str[i])==0)
                                        ans += val[i];
                        }
                }
                printf("%d\n", ans);
        }

        return 0;
}
