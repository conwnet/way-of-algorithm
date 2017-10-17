#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
int ans[maxn], p2, p3, n, cnt;

int main()
{
        p2 = p3 = 0;
        cnt = 1;
        ans[0] = 1;
        while(cnt<maxn) {
                if(ans[p2]*2+1 == ans[p3]*3+1) p2++;
                if(ans[p2]*2+1 < ans[p3]*3+1)
                        ans[cnt++] = ans[p2++]*2+1;
                else ans[cnt++] = ans[p3++]*3+1;
        }
        while(~scanf("%d", &n)) {
                printf("%d\n", ans[n-1]);
        }

        return 0;
}


/**
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 10000000;
typedef long long ll;
ll heap[maxn];
int qc, cnt, arr[maxn];

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

void cal_arr()
{
        qc = cnt = 0;
        push(1);
        while(cnt<maxn) {
                ll t = heap[1]; pop();
                if(t==arr[cnt-1]) continue;
                arr[cnt++] = t;
                push(t*2+1); push(t*3+1);
        }
}

int main()
{
        int n;
        cal_arr();
        while(0 && ~scanf("%d", &n)) {
                printf("%lld\n", arr[n-1]);
        }

        return 0;
}
*/
