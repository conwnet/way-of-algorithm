#include <stdio.h>
#include <string.h>

int main()
{
    int N, i, j, x[20000], y[20000], rand[20000], cnt;

    scanf("%d", &N);
    for(i=0; i<N; i++){
        scanf("%d%d", &x[i], &y[i]);
    }
    memset(rand, 0, sizeof(rand));
    for(i=0; i<N; i++){
        cnt = 0;
        for(j=0; j<i; j++){
            if(x[j]<=x[i]) cnt++;
        }
        rand[cnt]++;
    }
    for(i=0; i<N; i++) printf("%d\n", rand[i]);

    return 0;
}
