#include <stdio.h>
#include <string.h>
#include <time.h>

void print(time_t t)
{
        char week[50];
        struct tm T = *localtime(&t);
        printf("%d-%02d-%02d ", T.tm_year+1900, T.tm_mon+1, T.tm_mday);
        strcpy(week, asctime(&T));
        if('S'==week[0] && 'u'==week[1]) printf("Sunday\n");
        else if('M'==week[0] && 'o'==week[1]) printf("Monday\n");
        else if('T'==week[0] && 'u'==week[1]) printf("Tuesday\n");
        else if('W'==week[0] && 'e'==week[1]) printf("Wednesday\n");
        else if('T'==week[0] && 'h'==week[1]) printf("Thursday\n");
        else if('F'==week[0] && 'r'==week[1]) printf("Friday\n");
        else if('S'==week[0] && 'a'==week[1]) printf("Saturday\n");
}

int main()
{
        int n;
        time_t t = time(0);
        struct tm T = *localtime(&t);
        time_t ti = mktime(&T);
        time_t tt;
        T.tm_year -= 15;
        T.tm_mon -= 10;
        T.tm_mday -= 13;
        while(scanf("%d", &n)) {
                if(n<0) break;
                tt = ti;
                tt += n*86400;
                print(tt);
        }

        return 0;
}
