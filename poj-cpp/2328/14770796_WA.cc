#include <stdio.h>
#include <string.h>

int main()
{
        char tmp[30], ans[30];
        int n;
        while(1) {
                int l = 1, r = 10;
                scanf("%d", &n);
                if(n==0) return 0;
                int ok = 0;
                while(scanf("%s%s", tmp, ans)) {
                        if(ans[0]=='o') {
                                if(n>r || n<l) ok = -1;
                                break;
                        }
                        if(ok<0) {scanf("%d", &n); continue;}
                        if(ans[0]=='l') l = n+1;
                        else if(ans[0]=='h') r = n-1;
                        if(l>r) ok = -1;
                        scanf("%d", &n);
                }
                if(ok<0) printf("Stan is dishonest\n");
                else printf("Stan may be honest\n");
        }

        return 0;
}
