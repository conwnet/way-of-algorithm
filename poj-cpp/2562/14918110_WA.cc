#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

void Strrev(char *str)
{
        int l = strlen(str), bl = l>>1;
        for(int i=0; i<bl; i++)
                swap(str[i], str[l-i-1]);
}

int main()
{
        char a[15], b[15];

        while(scanf("%s%s", a, b)) {
                if(a[0]=='0' && b[0]=='0') break;
                int la = strlen(a), lb = strlen(b);
                Strrev(a); Strrev(b);
                if(la < lb) { swap(a, b); la = lb; }
                for(int i=0; i<lb; i++)
                        a[i] += b[i]-'0';
                int ans = 0;
                for(int i=0; i<la; i++) {
                        if(a[i]>'9') {
                                a[i+1] += 1;
                                a[i] -= 10;
                                ans++;
                        }
                }
                if(!ans) printf("No carry operation.\n");
                else if(ans==1) printf("1 carry operation.\n");
                else printf("%d carry operations.\n", ans);
        }

        return 0;
}
