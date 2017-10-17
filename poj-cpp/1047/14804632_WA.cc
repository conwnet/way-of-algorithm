#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char lstr[80];
int lnum[80], tmp[80];

int main()
{
        freopen("in.txt", "r", stdin);
        while(~scanf("%s", lstr)) {
                int len = strlen(lstr);
                int faild = 0;
                for(int i=2; i<=len; i++) {
                        for(int j=0; j<len; j++) lnum[j] = lstr[j]-'0';
                        for(int j=len-1; j>=0; j--) {
                                lnum[j] *= i;
                        }
                        for(int j=len-1; j>0; j--) {
                                lnum[j-1] += lnum[j]/10;
                                lnum[j] %= 10;
                        }
                        for(int j=0; j<len; j++) tmp[j] = lstr[j]-'0';
                        sort(lnum, lnum+len);
                        sort(tmp, tmp+len);
                        for(int j=0; j<len; j++) {
                                if(tmp[j]!=lnum[j]) {
                                        faild = 1;
                                        break;
                                }
                        }
                        if(faild) break;
                }
                if(faild) printf("%s is not cyclic\n", lstr);
                else printf("%s is cyclic\n", lstr);
        }

        return 0;
}