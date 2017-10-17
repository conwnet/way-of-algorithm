#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int max_n = 200005;

int n, k;
int rank[max_n], tmp[max_n];

int cmp_sa(int a, int b)
{
        if(rank[a] != rank[b])
                return rank[a] < rank[b];
        int ra = a+k<=n ? rank[a+k] : -1;
        int rb = b+k<=n ? rank[b+k] : -1;
        return ra < rb;
}

void cal_sa(string str, int *sa)
{
        n = str.length();

        for(int i=0; i<=n; i++) {
                sa[i] = i;
                rank[i] = str[i];
        }
        for(k=1; k<=n; k<<=1) {
                sort(sa, sa+n+1, cmp_sa);
                tmp[sa[0]] = 0;
                for(int i=1; i<=n; i++)
                        tmp[sa[i]] = tmp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);
                for(int i=0; i<=n; i++)
                        rank[i] = tmp[i];
        }
}

void cal_lcp(string str, int *sa, int *lcp)
{
        for(int i=0; i<=n; i++)
                rank[sa[i]] = i;
        int h = 0;
        //lcp[0] = 0;
        for(int i=0; i<n; i++) {
                int j = sa[rank[i]-1];
                if(h>0) h--;
                for(; j+h<n && i+h<n; h++)
                        if(str[j+h]!=str[i+h])
                                break;
                lcp[rank[i]-1] = h;
        }
}

string str, s1, s2;
int lcp[max_n], sa[max_n];

int main()
{
        cin >> s1 >> s2;
        int s1l = s1.length();
        str = s1 + s2;
        cal_sa(str, sa);
        cal_lcp(str, sa, lcp);
        int ans = 0;
        for(int i=0; i<n; i++)
                if((sa[i]<s1l) != (sa[i+1]<s1l) && lcp[i]>ans)
                        ans = lcp[i];
        printf("%d\n", ans);

        return 0;
}






