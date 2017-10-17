#include <stdio.h>
#include <string.h>

int main()
{
        int star[20000], cnt[20000], N, rand[20000], i, j, t;

        scanf("%d", &N);
        for(i=0; i<N; i++){
                scanf("%d%d", &star[i], &t);
        }
        memset(cnt, 0, sizeof(cnt));
        for(i=0; i<N; i++){
                for(j=i-1, t=0; j>=0; j--){
                        if(star[j]<=star[i])
                                t++;
                }
                cnt[i] = t;
        }
        memset(rand, 0, sizeof(rand));
        for(i=0; i<N; i++){
                rand[cnt[i]]++;
        }
        for(i=0; i<N; i++){
                printf("%d\n", rand[i]);
        }

        return 0;
}
