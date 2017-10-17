#include <stdio.h>
#include <string.h>

int main()
{
        double a, b, c;

        while(~scanf("%lf%lf%lf", &a, &b, &c)) {
                if(a==0 && b==0 && c==0) break;
                int pos = 0;
                if(a<=4.5 && b>=150 && c>=200) {
                        printf("Wide Receiver");
                        pos = 1;
                }
                if(a<=6.0 && b>=300 && c>=500) {
                        if(pos) printf(" ");
                        printf("Lineman");
                        pos = 1;
                }
                if(a<=5.0 && b>=200 && c>=300) {
                        if(pos) printf(" ");
                        printf("Quarterback");
                        pos = 1;
                }
                if(!pos) printf("No positions");
                printf("\n");
        }

        return 0;
}
