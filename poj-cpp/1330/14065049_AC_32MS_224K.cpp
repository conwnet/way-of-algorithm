#include <stdio.h>
#include <string.h>

int main()
{
        int p[20000], N, T, i, a, b, s, t, ok;

        scanf("%d", &T);
        while(T--) {
                for(i=0; i<20000; i++) p[i] = i;
                scanf("%d", &N);
                for(i=1; i<N; i++) {
                        scanf("%d%d", &a, &b);
                        p[b] = a;
                }
                scanf("%d%d", &a, &b);
                ok = 0;
                for(t=a; p[t]!=t; t=p[t]) {
                        for(s=b; p[s]!=s; s=p[s]) {
                                if(s==t) {
                                        ok = 1;
                                        break;
                                }
                        }
                        if(ok) break;
                }
                printf("%d\n", s);
        }

        return 0;
}
