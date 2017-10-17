#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef long long ll;

ll fact[128];
int f_cnt;
int S = 20;

ll pow_mod(ll, ll, ll);
ll mul_mod(ll, ll, ll);
int miller_rabin(ll n);
void find_fact(ll n);
ll gcd(ll, ll);

int main()
{
        int T;
        ll n;

        scanf("%d", &T);
        while(T--) {
                scanf("%lld", &n);
                if(miller_rabin(n))
                        printf("Prime\n");
                else {
                        f_cnt = 0;
                        find_fact(n);
                        ll ans = fact[0];
                        for(int i=1; i<f_cnt; i++)
                                if(fact[i]<ans)
                                        ans = fact[i];
                        printf("%lld\n", ans);
                }
        }

        return 0;
}

ll mul_mod(ll a, ll b, ll n)
{
        a %= n; b %= n;
        ll res = 0;
        while(b) {
                if(b&1) {
                        res += a;
                        res %= n;
                }
                a <<= 1;
                if(a>=n) a %= n;
                b >>= 1;
        }
        return res;
}

ll pow_mod(ll a, ll x, ll n)
{
        if(x==1) return a % n;
        ll t = pow_mod(a, x>>1, n);
        t = mul_mod(t, t, n);
        if(x&1) t = mul_mod(t, a, n);
        return t;
}

int check(ll a, ll n, ll x, ll t)
{
        ll res = pow_mod(a, x, n);
        ll last = res;
        for(int i=1; i<=t; i++) {
                res = mul_mod(res, res, n);
                if(res==1 && last!=1 && last!=n-1)
                        return 1;
                last = res;
        }
        if(res!=1) return 1;
        return 0;
}

int miller_rabin(ll n)
{
        if(n<2) return 0;
        if(n==2) return 1;
        if(!(n&1)) return 0;
        ll x = n-1;
        ll t = 0;
        while(!(x&1)) {
                x >>= 1;
                t++;
        }
        for(int i=0; i<S; i++) {
                ll a = rand()%(n-1)+1;
                if(check(a, n, x, t))
                        return 0;
        }
        return 1;
}

ll gcd(ll a, ll b)
{
        return a%b ? gcd(b, a%b) : b;
}

ll pollard_rho(ll x, ll c)
{
        ll i = 1, k = 2;
        ll tx = rand()%(x-1)+1;
        ll y = tx;
        while(1) {
                i++;
                tx = (mul_mod(tx, tx, x)+c) % x;
                ll d = gcd(y-tx, x);
                if(d!=1 && d!=x) return d;
                if(y==tx) return x;
                if(i==k) {
                        y = tx;
                        k += k;
                }
        }

}

void find_fact(ll n)
{
        if(miller_rabin(n)) {
                fact[f_cnt++] = n;
                return ;
        }
        ll p = n;
        while(p>=n)
                p = pollard_rho(p, rand()%(n-1)+1);
        find_fact(p);
        find_fact(n/p);
}

