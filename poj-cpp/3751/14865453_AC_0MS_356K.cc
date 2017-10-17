#include <stdio.h>

int main()
{
        int ye, mo, da, ho, mi, se, T, ok;

        scanf("%d", &T);
        while(T--) {
                scanf("%d/%d/%d-%d:%d:%d", &ye, &mo, &da, &ho, &mi, &se);
                if(ho>=12) ok = 1;
                else ok = 0;
                if(ho>12) ho -= 12;
                else if(ho==0) ho = 12;
                printf("%02d/%02d/%02d-%02d:%02d:%02d", mo, da, ye, ho, mi, se);
                printf("%s\n", ok ? "pm": "am");
        }

        return 0;
}
