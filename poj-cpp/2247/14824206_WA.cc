#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int hum[6000];
void solve()
{
        int p, p2, p3, p5, p7, mins;
        p2 = p3 = p5 = p7 = 0; p = 1;
        hum[0] = 1;
        while(p<5842) {
                mins = min(hum[p2]*2, hum[p3]*3);
                mins = min(mins, hum[p5]*5); mins = min(mins, hum[p7]*7);
                hum[p++] = mins;
                if(hum[p2]*2==mins) p2++; if(hum[p3]*3==mins) p3++;
                if(hum[p5]*5==mins) p5++; if(hum[p7]*7==mins) p7++;
        }
}

int main()
{
        int n;
        solve();
        while(scanf("%d", &n) && n) {
                if(11==n) printf("The %dth humble number is ", n);
                else if(12==n) printf("The %dth humble number is ", n);
                else if(13==n) printf("The %dth humble number is ", n);
                else if(1==n%10) printf("The %dst humble number is ", n);
                else if(2==n%10) printf("The %dnd humble number is ", n);
                else if(3==n%10) printf("The %drd humble number is ", n);
                else printf("The %dth humble number is ", n);
                printf("%d.\n", hum[n-1]);
        }

        return 0;
}
