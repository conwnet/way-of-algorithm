#include <stdio.h>
#include <math.h>

double dot[1024][2];

int main()
{
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++)
                scanf("%lf%lf", &dot[i][0], &dot[i][1]);
        int ans = 0;
        for(int i=0; i<N; i++) {
                for(int j=i+1; j<N; j++) {
                        double d = (dot[j][1]-dot[i][1]) / (dot[j][0]-dot[i][0]);
                        int cnt = 2;
                        for(int k=j+1; k<N; k++) {
                                if(fabs((dot[k][1]-dot[i][1])/(dot[k][0]-dot[i][0])-d)<1e-8)
                                        cnt++;
                        }
                        if(cnt>ans) ans = cnt;
                }
        }
        printf("%d\n", ans);

        return 0;
}
