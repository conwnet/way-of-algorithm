#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

int main()
{
        priority_queue<double> pq;
        int N, i;
        double t, t1, t2, ans=0;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                scanf("%lf", &t);
                pq.push(t);
        }
        while(pq.size()!=1) {
                t1 = pq.top(); pq.pop();
                t2 = pq.top(); pq.pop();
                t = 2*sqrt(t1*t2);
                pq.push(t);
        }
        printf("%.3lf", pq.top());

        return 0;
}
