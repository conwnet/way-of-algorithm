#include <stdio.h>
#include <string>
#include <map>

using namespace std;

typedef char String[15];

int main(){
    map<string, string> mp;
    char str1[15], str2[15], str[15];
    char tch;

    scanf("%s%s", str1, str2);
    mp[str2] = str1;
    while(1){
        if(getchar()=='\n' && (tch=getchar())=='\n') break;
        str1[0] = tch;
        scanf("%s%s", &str1[1], str2);
        mp[str2] = str1;
    }

    while(~scanf("%s", str)){
        if(mp[str].empty()) printf("eh\n");
        else printf("%s\n", mp[str].c_str());
    }

    return 0;
}
