#include <stdio.h>
#include <string.h>

int r[60000], N, M;

int findr(int a)
{
        return r[a]==a ? a : findr(r[a]);
}

int main()
{
        int i, a, b, cnt[60000], nCase=1;

        while(~scanf("%d%d", &N, &M)){
                if(N==0 && M==0) break;
                for(i=0; i<=N; i++){
                        r[i] = i;
                }
                for(i=0; i<M; i++){
                        scanf("%d%d", &a, &b);
                        int x = findr(a);
                        int y = findr(b);

                        r[y] = x;
                }
                memset(cnt, 0, sizeof(cnt));
                for(i=1; i<=N; i++){
                        cnt[r[i]] = 1;
                }
                int rzt = 0;
                for(i=0; i<=N; i++){
                        if(cnt[i]) rzt++;
                }
                printf("Case %d: %d\n", nCase++, rzt);
        }
        return 0;
}
