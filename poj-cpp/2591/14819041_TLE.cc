#include <stdio.h>
#include <algorithm>

using namespace std;

const int maxn = 4000000;
typedef long long ll;
ll que[maxn], arr[maxn];
int nc, cnt;

void push(ll x)
{
        int p = ++nc;
        while(p>>1 >= 1) {
                if(que[p>>1] < x) break;
                que[p] = que[p>>1];
                p >>= 1;
        }
        que[p] = x;
}

void pop()
{
        ll x = que[nc--];
        int p = 1;
        while(p<<1 <= nc) {
                int l = p<<1;
                if(l+1<=nc && que[l]>que[l+1])
                        l = l+1;
                if(x < que[l]) break;
                que[p] = que[l];
                p = l;
        }
        que[p] = x;
}

void cal_arr()
{
        nc = cnt = 0;
        push(1);
        for(int i=0; cnt<maxn; i++) {
                ll t = que[1]; pop();
                if(t==arr[cnt-1]) continue;
                arr[cnt++] = t;
                push(t*2+1); push(t*3+1);
        }
}

int main()
{
        int n;
        cal_arr();
        while(~scanf("%d", &n)) {
                printf("%lld\n", arr[n-1]);
        }

        return 0;
}

