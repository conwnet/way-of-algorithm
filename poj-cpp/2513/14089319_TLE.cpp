#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main()
{
        map<string, int> mp;
        char str[50];

        while(~scanf("%s", str)) {
                mp[str]++;
        }
        map<string, int>::iterator it;
        int cnt = 0;
        for(it=mp.begin(); it!=mp.end(); it++) {
                if(it->second%2!=0) cnt++;
        }
        if(cnt>2) printf("Impossible\n");
        else printf("Possible\n");

        return 0;
}
