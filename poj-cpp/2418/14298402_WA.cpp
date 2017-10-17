#include <stdio.h>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

int main()
{
	map<string, int> mp;
	int cnt;
	char str[35];

	cnt = 0;
	while(gets(str)) {
		if(!isalpha(str[0])) continue;
		cnt++;
		mp[str] ++;
	}

	map<string, int>::iterator it;
	for(it=mp.begin(); it!=mp.end(); it++) {
		printf("%s %.4lf\n", it->first.c_str(), (double)it->second*100/cnt);
	}

	return 0;
}
