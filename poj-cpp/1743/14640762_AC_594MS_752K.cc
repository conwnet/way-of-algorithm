#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 20005;

int str[maxn];
int sa_k, rank[maxn], sa[maxn];
int n, lcp[maxn], tmp[maxn];

int cmp_sa(int a, int b)
{
        if(rank[a]!=rank[b])
                return rank[a] < rank[b];
        int ra = a+sa_k<=n ? rank[a+sa_k] : -1;
        int rb = b+sa_k<=n ? rank[b+sa_k] : -1;
        return ra < rb;
}

void cal_sa()
{
        for(int i=0; i<=n; i++) {
                rank[i] = str[i];
                sa[i] = i;
        }
        rank[n] = -1;
        for(sa_k=1; sa_k<=n; sa_k<<=1) {
                sort(sa, sa+n+1, cmp_sa);
                tmp[sa[0]] = 0;
                for(int i=1; i<=n; i++) {
                        tmp[sa[i]] = tmp[sa[i-1]] +
                        (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
                }
                for(int i=0; i<=n; i++)
                        rank[i] = tmp[i];
        }
}

void cal_lcp()
{
        for(int i=0; i<=n; i++)
                rank[sa[i]] = i;
        int h = 0;
        for(int i=0; i<n; i++) {
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; i+h<n && j+h<n; h++)
                        if(str[i+h]!=str[j+h])
                                break;
                lcp[rank[i]-1] = h;
        }
}

int is_ok(int len)
{
        int maxs, mins, i=1;
        while(1) {
                while(i<n && lcp[i]<len)
                        i++;
                if(i>=n) break;
                int maxs = sa[i];
                int mins = sa[i];
                for(; i<n && lcp[i]>=len; i++) {
                        maxs = max(maxs, sa[i+1]);
                        mins = min(mins, sa[i+1]);
                }
                if(maxs-mins >= len)
                        return 1;
        }
        return 0;
}

int main()
{
        while(scanf("%d", &n) && n) {
                for(int i=0; i<n; i++)
                        scanf("%d", &str[i]);
                for(int i=1; i<n; i++)
                        str[i-1] = str[i]-str[i-1]+100;
                cal_sa();
                cal_lcp();
                int l = 0;
                int r = n;
                while(l<r) {
                        int m = (l+r) >> 1;
                        if(is_ok(m)) l = m+1;
                        else r = m;
                }
                printf("%d\n", l<5?0:l);
        }

        return 0;
}
