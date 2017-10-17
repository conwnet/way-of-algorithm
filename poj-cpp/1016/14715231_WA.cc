#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

typedef long long ll;

ll change(ll n)
{
        int cnt[10];
        memset(cnt, 0, sizeof(cnt));
        while(n) {
                cnt[n%10]++;
                n /= 10;
        }
        ll ret = 0;
        for(int i=0; i<10; i++) {
                if(cnt[i]) {
                        int t = cnt[i]*10 + i;
                        if(t>=100) ret *= 1000;
                        else ret *= 100;
                        ret += t;
                }
        }
        return ret;
}

int main()
{
        ll n, num;
        set<ll> st;

        while(scanf("%lld", &num)) {
                if(num==-1) break;
                n = num;
                st.clear();
                st.insert(n);
                int i;
                for(i=0; i<15; i++) {
                        n = change(n);
                        if(st.find(n)!=st.end()) break;
                        st.insert(n);
                }
                if(i==0) printf("%lld is self-inventorying\n", num);
                else if(i==15) printf("%lld can not be classified after 15 iterations\n", num);
                else if(change(n)==n) printf("%lld is self-inventorying after %d steps\n", num, i);
                else {
                        int j;
                        ll t = n;
                        for(j=1; j<16; j++) {
                                t = change(t);
                                if(t==n) break;
                        }
                        printf("%lld enters an inventory loop of length %d\n", num, j);
                }
        }

        return 0;
}
