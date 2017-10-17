#include <stdio.h>
#include <queue>

using namespace std;

struct cmp{
    int operator ()(int a, int b){
        return a>b;
    }
};

int main(){
    priority_queue<int, vector<int>, cmp> pq;
    int t;
    long long N, i, cnt;

    scanf("%lld", &N);
    for(i=0; i<N; i++){
        scanf("%d", &t);
        pq.push(t);
    }
    cnt = 0;
    while(pq.size()>1){
        t = pq.top();
        pq.pop();
        t += pq.top();
        pq.pop();
        cnt += t;
        pq.push(t);
    }
    printf("%lld\n", cnt);


    return 0;
}