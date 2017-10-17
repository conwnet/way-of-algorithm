
#include <stdio.h>
#include <string.h>

int arr[1100000];

int get_n(int n);
int get(int n, int m);

int main()
{
        int N;

        scanf("%d", &N);
        memset(arr, 0, sizeof(arr));
        arr[1] = 1;
        printf("%d\n", get_n(N));

        return 0;
}

int get_n(int n)
{
        int ans = 0;

        if(arr[n]) return arr[n];
        else {
                ans += get_n(n-1);
                if(n%2==0) ans += get_n(n/2);
        }

        return arr[n] = ans%1000000000;
}
