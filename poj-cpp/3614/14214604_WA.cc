#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Lot{
        int spf, n;
        Lot(int a, int b)
        {
                spf = a;
                n = b;
        }
        bool operator < (const Lot& b) const {
                return spf<b.spf;
        }
        bool operator < (const int& b) const {
                return spf<b;
        }
};

struct Sun
{
        int s, l;
        bool operator < (const Sun& b) const {
                if(s==b.s) return l<b.l;
                return s<b.s;
        }
};

Sun sun[2600];
vector<Lot> lot;
int C, L, ans;

int cmp(Lot a, Lot b)
{
        return a.spf<b.spf;
}

int main()
{
        int i, j, spf, n;

        scanf("%d%d", &L, &C);
        for(i=0; i<L; i++) scanf("%d%d", &sun[i].s, &sun[i].l);
        for(i=0; i<C; i++) {
                scanf("%d%d", &spf, &n);
                lot.push_back(Lot(spf, n));
        }
        sort(lot.begin(), lot.end());
        ///sort(sun, sun+L);
        ans = 0;
        for(i=0; i<L; i++) {
                vector<Lot>::iterator it = lower_bound(lot.begin(), lot.end(), sun[i].s);
                if(!(sun[i].l<(*it).spf) && (*it).n>0) {
                        (*it).n--;
                        if((*it).n==0) lot.erase(it);
                        ans++;
                }
        }
        printf("%d\n", ans);

        return 0;
}
