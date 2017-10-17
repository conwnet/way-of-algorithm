#include <stdio.h>
#include <string.h>
#include <math.h>

int prime[200000], arr[200000];

void get_prime();

int main()
{
        int n, mins, cnt;
        get_prime();
        for(int i=1; i<200000; i++) {
               prime[i] += prime[i-1];
        }

        //for(int i=0; i<10; i++) printf("%d ", prime[i]);
        while(scanf("%d", &n) && n) {
                cnt = 0;
                for(int i=0; i<=n; i++) {
                        for(int j=0; j<i; j++) {
                                if(prime[i]-prime[j]==n) cnt++;
                        }
                }
                printf("%d\n", cnt);
        }


        return 0;
}

void get_prime()
{
        int i, j, t;

        t = sqrt(200000)+0.5;
        memset(arr, 0, sizeof(arr));
        for(i=2; i<t; i++) {
                if(!arr[i])
                        for(j=i*i; j<200000; j+=i) {
                                arr[j] = 1;
                        }
        }
        prime[i] = 0;
        for(i=2, t=1; i<200000; i++) {
                if(!arr[i]) prime[t++] = i;
        }

}
