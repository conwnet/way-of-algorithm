#include <stdio.h>

int main()
{
        int m, n, arr1[20], arr2[20], i, j, cnt, na, ma;

        scanf("%d%d", &m, &n);
        ma = na = 0;
        while(m) {
                arr1[ma++] = m%10;
                m /= 10;
        }
        while(n) {
                arr2[na++] = n%10;
                n /= 10;
        }
        cnt = 0;
        for(i=0; i<ma; i++)
                for(j=0; j<na; j++)
                        cnt += arr1[i]*arr2[j];

        printf("%d\n", cnt);


        return 0;
}
