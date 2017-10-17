#include <stdio.h>

int dat[11000];
int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 32 };
char week[7][15] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
};

int main()
{
        for(int i=0; i<10000; i++) {
                int y = 2000+i;
                if(!(y%400) || !(y%4) && y%100)
                        dat[i] = 366;
                else dat[i] = 365;
        }
        int n, y, m, w;
        while(scanf("%d", &n)) {
                if(n<0) break;
                w = (5+n)%7;
                for(y=0; n>dat[y]; y++)
                        n -= dat[y];
                if(dat[y]==366) mon[1] = 29;
                else mon[1] = 28;
                for(m=0; n>mon[m]; m++)
                        n -= mon[m];
                printf("%d-%02d-%02d %s\n", 2000+y, 1+m, 1+n, week[w]);

        }

        return 0;
}
