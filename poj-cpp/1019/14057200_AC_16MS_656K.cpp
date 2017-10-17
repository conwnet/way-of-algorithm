#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define INF 2147483648

long long arr[102400000], sub_arr[1024000];

int main()
{
        int i, T, N, j, t, n, sl;
        char str[50];

        arr[0] = sub_arr[0] = 0;
        for(i=1; arr[i-1]<INF; i++) {
                sprintf(str, "%d", i);
                sub_arr[i] = sub_arr[i-1]+strlen(str);
                arr[i] = arr[i-1]+sub_arr[i];
        }
       // puts("test");
        for(i=1; sub_arr[i-1]<INF; i++) {
                for(j=1, t=1; j<i; j++) t = 10*t;
                sub_arr[i] = 9 * (long long)t * i;
        }
        sl = i;
       // for(j=1; j<=i; j++) sub_arr[j] *= j;
      //  printf("%lg\n%d\n%d\n", clock()/(double)CLOCKS_PER_SEC, sub_arr[i], i);
     //   for(i=1; i<13; i++) printf("%d ", sub_arr[i]);
        scanf("%d", &T);
        while(T--) {
                scanf("%d", &N);
                if(N==1) {
                        printf("1\n");
                        continue;
                }
                for(i=1; N>arr[i+1]; i++);
                N -= arr[i];
               // printf("N--%d\n", N);
                for(i=1; N>sub_arr[i] && i<=sl; i++)
                        N -= sub_arr[i];
                //printf("N--%d\n", N);

                if(N%i) n = N/i+1;
                else n = N/i;

                for(j=1, t=1; j<i; j++) t = 10*t;
                n = t+n-1;
                //printf("n--%d\n", n);
                if(N%i) t = N%i;
                else t = i;

               // printf("t--%d\n", t);
                sprintf(str, "%d", n);
                n = strlen(str);
                if(t==0) printf("%c\n", str[n-1]);
                else printf("%c\n", str[t-1]);

        }

        return 0;
}

/**<

123456789101112
9
90
900
9000



 */
