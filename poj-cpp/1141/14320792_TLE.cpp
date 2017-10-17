#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

string dp[128][128];
string str;

string dfs(int s, int e)
{
	string ss;
	if(s>e) return "";
	if(dp[s][e].size()>0) return dp[s][e];
	if(str[s]=='(' && str[e]==')')
		ss = "(" + dfs(s+1, e-1) + ")";
	else if(str[s]=='[' && str[e]==']')
		ss = "[" + dfs(s+1, e-1) + "]";
	else if(str[s]==' ') ss = " " + dfs(s+1, e);
	else if(str[e]==' ') ss = dfs(s, e-1) + " ";
	else {
		string s1 = (str[s]=='(' || str[s]==')'?"()":"[]") + dfs(s+1, e);
		string s2 = dfs(s, e-1) + (str[e]=='(' || str[e]==')'?"()":"[]");
		ss = s1.size()<s2.size()?s1:s2;
	}
	for(int i=s+1; i<e; i++) {
		string t = dfs(s, i) + dfs(i+1, e);
		if(t.size()<ss.size()) ss = t;
	}
	return dp[s][e] = ss;
}

int main()
{
	char ss[128];

	gets(ss);
	str = ss;
	printf("%s\n", dfs(0, str.size()-1).c_str());
	return 0;
}