#include <stdio.h>
#include <string.h>

int main()
{
        for(int i=2992; i<10000; i++) {
                int n = i;
                int s = 0;
                while(n) {
                        s += n%16;
                        n /= 16;
                }
                int s1 = i%10 + (i/10)%10 + (i/100)%10 + i/1000;
                if(s==s1) printf("%d\n", i);
        }

        return 0;
}
