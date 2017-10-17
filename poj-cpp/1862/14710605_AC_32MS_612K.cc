#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
        priority_queue<double> pq;
        int N;
        double n;

        scanf("%d", &N);
        for(int i=0; i<N; i++) {
                scanf("%lf", &n);
                pq.push(n);
        }
        while(pq.size()>1) {
                double d1 = pq.top();
                pq.pop();
                double d2 = pq.top();
                pq.pop();
                pq.push(sqrt(d1*d2)*2);
        }
        printf("%.3f\n", pq.top());

        return 0;
}

