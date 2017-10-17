#include <stdio.h>
#include <string.h>

int sum[15];
char name[15][50];

int main()
{
        int a, b, c, N;

        while(scanf("%d", &N)) {
                if(N<0) break;
                for(int i=0; i<N; i++) {
                        scanf("%d%d%d%s", &a, &b, &c, name[i]);
                        sum[i] = a*b*c;
                }
                int maxs = sum[0], maxf = 0;
                int mins = sum[0], minf = 0;
                for(int i=1; i<N; i++) {
                        if(sum[i]>maxs) {
                                maxs = sum[i];
                                maxf = i;
                        }
                        if(sum[i]<mins) {
                                mins = sum[i];
                                minf = i;
                        }
                }
                printf("%s took clay from %s.\n", name[maxf], name[minf]);
        }

        return 0;
}
