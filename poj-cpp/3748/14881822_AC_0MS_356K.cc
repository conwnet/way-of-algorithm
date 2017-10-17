#include <stdio.h>

int main()
{
        int r, x, y;
        scanf("%x,%d,%d", &r, &x, &y);
        if(r&1<<x) r -= 1<<x;
        r |= 1<<y;
        r |= 1<<y-1;
        if(r&1<<y-2) r -= 1<<y-2;
        printf("%x\n", r);

        return 0;
}
