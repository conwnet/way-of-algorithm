#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p[30010], arr[30010];

int findp(int a)
{
        return p[a]==a ? a : p[a] = findp(p[a]);
}

int main()
{
        int i, j, N, M, n, t, p1, p2;

        while(scanf("%d%d", &N, &M)!=EOF) {
                if(N==0 && M==0) break;
                for(i=0; i<30010; i++) p[i] = i;
                //memset(p, 0, sizeof(p));
                while(M--) {
                        scanf("%d", &n);
                        for(i=0; i<n; i++) scanf("%d", &arr[i]);
                        for(i=1; i<n; i++) {
                                p1 = findp(arr[i-1]);
                                p2 = findp(arr[i]);
                                if(p1>p2) {
                                        p[p1] = p2;
                                } else {
                                        p[p2] = p1;
                                }
                        }
                }
               // printf("====%d\n", findp(0));
                for(i=0, t=0; i<N; i++) {
                        if(findp(i)==0) t++;
                }
                printf("%d\n", t);
        }


        return 0;
}
