#include <stdio.h>
#include <string.h>

int main()
{
        char tmp[30], ans[30];
        int n;
        while(1) {
                int l = 1, r = 10, ok = 0;
                while(scanf("%d", &n)) {
                        if(n==0) return 0;
                        scanf("%s%s", tmp, ans);
                        if(ans[0]=='o') {
                                if(n<l || n>r) ok = 1;
                                break;
                        } else if(ans[0]=='l') {
                                if(l<n+1) l = n+1;
                        } else {
                                if(r>n-1) r = n-1;
                        }
                        if(ok) continue;
                        if(l>r) ok = 1;
                }
                if(ok) printf("Stan is dishonest\n");
                else printf("Stan may be honest\n");
        }

        return 0;
}


