#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;


int main(){
    char anc[128], con[128], tmp[128];
    int a[26], c[26];
    int alength, clength, flag, i;

    while(scanf("%s", anc)!=EOF){
        flag = 1;
        scanf("%s", con);
        alength = strlen(anc);
        memset(a, 0, 104);
        memset(c, 0, 104);
        for(i=0; i<alength; i++){
            a[anc[i]-'A']++;
            c[con[i]-'A']++;
        }
        sort(a, a+26);
        sort(c, c+26);
        for(i=0; i<26; i++){
            if(a[i]!=c[i]){
                flag = 0;
                break;
            }
        }
        flag?printf("YES\n"):printf("NO\n");
    }

    return 0;
}
