#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
        char str[80];
        int sup, dic[26][26];
        while(scanf("%s", str)) {
                if(str[0]=='*') break;
                int l = strlen(str);
                sup = 0;
                for(int d=1; d<l; d++) {
                        memset(dic, 0, sizeof(dic));
                        for(int i=0; i+d<l; i++) {
                                if(!dic[str[i]-'A'][str[i+d]-'A']) {
                                        dic[str[i]-'A'][str[i+d]-'A'] = 1;
                                } else {sup = 1; break;}
                        }
                        if(sup) break;
                }
                if(sup) printf("%s is NOT surprising.\n", str);
                else printf("%s is surprising.\n", str);
        }

        return 0;
}
