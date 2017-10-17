#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int N, K, vst[300000], time[100000];

int bfs(int n, int k);

int main(){
    int s, i, t, mins;

    while(~scanf("%d%d", &N, &K)){
        if(N>=K){
            printf("%d\n", N-K);
            continue;
        }
        mins = N-K;
        s = 0;
        t = N;
        if(t<K){
            s++;
            t *= 2;
        }
        bfs(N, K);
        printf("%d\n", time[K]);
    }

    return 0;
}

int bfs(int n, int k){
    queue<int> q;

    memset(vst, 0, 1200000);
    q.push(n);
    while(1){
        if(q.front()==k) return 1;
        if(q.front()>0 && !vst[q.front()-1]){
            vst[q.front()-1] = 1;
            time[q.front()-1] = time[q.front()]+1;
            q.push(q.front()-1);
        }
        if(q.front()<k && !vst[q.front()+1]){
            vst[q.front()+1] = 1;
            time[q.front()+1] = time[q.front()]+1;
            q.push(q.front()+1);
        }
        if(q.front()<k && !vst[q.front()*2]){
            vst[q.front()*2] = 1;
            time[q.front()*2] = time[q.front()]+1;
            q.push(q.front()*2);
        }
        q.pop();
    }

    return 0;
}