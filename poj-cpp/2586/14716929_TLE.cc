#include <stdio.h>

int main()
{
        int s, d;

        while(~scanf("%d%d", &s, &d)) {
                int ans = -1;
                for(int i=0; i<1<<12; i++) {
                        int j;
                        for(j=0; j<8; j++) {
                                int tmp = 0;
                                for(int k=0; k<5; k++)
                                        if(i & 1<<(j+k)) tmp += s;
                                        else tmp -= d;
                                if(tmp>=0) break;
                        }
                        if(j!=8) continue;
                        int sum = 0;
                        for(int j=0; j<12; j++)
                                if(i & 1<<j) sum += s;
                                else sum -= d;
                        if(sum > ans) ans = sum;
                }
                if(ans>=0) printf("%d\n", ans);
                else printf("Deficit\n");
        }
        return 0;
}
