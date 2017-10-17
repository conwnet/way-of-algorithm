#include <stdio.h>

int main()
{
        int n, sum;

        while(scanf("%d", &n) && n) {
                while(n>9) {
                        sum = 0;
                        while(n/10) {
                                sum += n%10;
                                n /= 10;
                        }
                        n += sum;
                }
                printf("%d\n", n);
        }

        return 0;
}
