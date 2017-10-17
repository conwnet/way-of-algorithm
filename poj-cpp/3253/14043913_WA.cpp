
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
        int arr[30000], N, i, t1, t2, rzt, t;
        priority_queue<int, vector<int>, greater<int> > pq;

        scanf("%d", &N);
        for(i=0; i<N; i++){
                scanf("%d", &t);
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
        printf("%d\n", rzt);

        return 0;
}
