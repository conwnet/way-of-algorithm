#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int maxn = 10005;
int tmp[maxn], arr[maxn], ans;

int Merge(int *arr1, int l1, int *arr2, int l2)
{
        int r = 0, i = 0, j = 0;
        while(i<l1 && j<l2) {
                if(arr1[i]<arr2[j]) {
                        tmp[r++] = arr1[i++];
                } else {
                        ans += l1-i;
                        tmp[r++] = arr2[j++];
                }
        }
        while(i<l1) tmp[r++] = arr1[i++];
        while(j<l2) tmp[r++] = arr2[j++];
        for(i=0; i<r; i++) arr1[i] = tmp[i];
}

void msort(int *arr, int n)
{
        if(n>1) {
                int m = n >> 1;
                msort(arr, m);
                msort(arr+m, n-m);
                Merge(arr, m, arr+m, n-m);
        }
}

int main()
{
        int T, N;

        //scanf("%d", &T);
        while(scanf("%d", &N) && N) {
                ;
                for(int i=0; i<N; i++)
                        scanf("%d", &arr[i]);
                ans = 0;
                msort(arr, N);
                printf("%d\n", ans);
        }


        return 0;
}
