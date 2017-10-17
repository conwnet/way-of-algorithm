
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
        long long arr[30000], N, i, t1, t2, rzt, t;
        priority_queue<long long, vector<long long>, greater<long long> > pq;

        scanf("%lld", &N);
        for(i=0; i<N; i++){
                scanf("%lld", &t);
                pq.push(t);
        }
        rzt = 0;
        for(i=1; i<N; i++) {
                t1 = pq.top();
                pq.pop();
                t2 = pq.top();
                pq.pop();
                rzt += t1+t2;
                pq.push(t1+t2);
        }
        printf("%lld\n", rzt);

        return 0;
}
