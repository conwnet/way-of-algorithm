#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


const int maxn = 20010;
int sa[maxn], rank[maxn], lcp[maxn];
int len, sa_k, tmp[maxn];

int cmp_sa(int a, int b)
{
        if(rank[a]!=rank[b])
                return rank[a]<rank[b];
        int ra = a+sa_k<=len ? rank[a+sa_k] : -1;
        int rb = b+sa_k<=len ? rank[b+sa_k] : -1;
        return ra < rb;
}

void cal_sa(int *str, int n)
{
        len = n;
        for(int i=0; i<=len; i++) {
                sa[i] = i;
                rank[i] = str[i];
        }
        rank[len] = -1;
        for(sa_k=1; sa_k<=len; sa_k<<=1) {
                sort(sa, sa+len+1, cmp_sa);
                tmp[sa[0]] = 0;
                for(int i=1; i<=len; i++) {
                        tmp[sa[i]] = tmp[sa[i-1]] +
                        (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
                }
                for(int i=0; i<=len; i++)
                        rank[i] = tmp[i];
        }
}

void cal_lcp(int *str)
{
        for(int i=0; i<=len; i++)
                rank[sa[i]] = i;
        int h = 0;
        for(int i=0; i<len; i++) {
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; i+h<len && j+h<len; h++)
                        if(str[i+h]!=str[j+h])
                                break;
                lcp[rank[i]-1] = h;
        }
}

int arr[maxn], N, K;

int is_ok(int n)
{
        int cnt = 0;
        for(int i=0; i<len; i++) {
                if(lcp[i]>=n)
                        cnt++;
                else cnt = 0;
                if(cnt>=K-1) return 1;
        }
        return 0;
}

int main()
{
        scanf("%d%d", &N, &K);
        for(int i=0; i<N; i++)
                scanf("%d", &arr[i]);
        str[N] = 0;
        cal_sa(arr, N);
        cal_lcp(arr);
        int l = 0; int r = len*2;
        while(l<r) {
                int m = (l+r+1) >> 1;
                if(is_ok(m)) l = m;
                else r = m-1;
        }
        printf("%d\n", l);

        return 0;
}
