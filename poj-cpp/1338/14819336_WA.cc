#include <stdio.h>
#include <string.h>

typedef long long ll;
const int maxn = 1500;
ll heap[maxn];
int qc;

void push(ll x)
{
        int p = ++qc;
        while(p/2 >= 1) {
                if(heap[p/2] <= x) break;
                heap[p] = heap[p/2];
                p = p/2;
        }
        heap[p] = x;
}

void pop()
{
        ll x = heap[qc--];

        int p = 1;
        while(p*2 <= qc) {
                int l = p*2;
                if(l+1<=qc && heap[l]>heap[l+1])
                        l = l+1;
                if(x <= heap[l]) break;
                heap[p] = heap[l];
                p = l;
        }
        heap[p] = x;
}

int ans[maxn], cnt, n;

void solve()
{
        push(1);
        while(cnt<maxn) {
                int t = heap[1]; pop();
                if(ans[cnt-1]==t) continue;
                ans[cnt++] = t;
                push(t*2); push(t*3); push(t*5);
        }
}

int main()
{
        solve();
        while(scanf("%d", &n) && n)
                printf("%d\n", ans[n-1]);

        return 0;
}
