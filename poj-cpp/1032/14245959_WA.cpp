#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
        int N;
        priority_queue<int, vector<int>, greater<int> > pq;
        queue<int> Q;

        scanf("%d", &N);
        Q.push(N);
        while(!Q.empty()) {
                int n = Q.front(); Q.pop();
                if(n<5) pq.push(n);
                else {
                        Q.push(n/2);
                        Q.push(n-n/2);
                }
        }
        printf("%d", pq.top()); pq.pop();
        while(!pq.empty()) {
                printf(" %d", pq.top());
                pq.pop();
        }

        return 0;
}
