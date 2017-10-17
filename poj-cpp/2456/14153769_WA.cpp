#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[110000], N, M;

int judge(int n);

int main()
{
        int i, j, l, r, m;

        scanf("%d%d", &N, &M);
        for(i=0; i<N; i++) scanf("%d", &arr[i]);
        sort(arr, arr+N);
        l = 0;
        r = N-1;
        while(r-l>1) {
                m = (l+r)/2;
                if(judge(m)) l = m;
                else r = m;
        }
        printf("%d\n", arr[l]-arr[0]);

        return 0;
}

int judge(int n)
{
        int i, t=2, prev=n;
        int m = arr[n]-arr[0];

        for(i=n+1; i<N; i++) {
                if(arr[i]-arr[prev]>=m) {
                        prev = i;
                        t++;
                }
        }
        if(t>=M) return 1;
        else return 0;
}
