#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

string dp[128][128];
string str;

string dfs(int s, int e)
{
	if(s>e) return "";
	if(dp[s][e].size()>0) return dp[s][e];
	if(str[s]=='(' && str[e]==')')
		return dp[s][e] = "(" + dfs(s+1, e-1) + ")";
	else if(str[s]=='[' && str[e]==']')
		return dp[s][e] = "[" + dfs(s+1, e-1) + "]";
	else if(str[s]==' ') return dp[s][e] = " " + dfs(s+1, e);
	else if(str[e]==' ') return dp[s][e] = dfs(s, e-1) + " ";
	else {
		string s1 = (str[s]=='(' || str[s]==')'?"()":"[]") + dfs(s+1, e);
		string s2 = dfs(s, e-1) + (str[e]=='(' || str[e]==')'?"()":"[]");
		return dp[s][e] = s1.size()<s2.size()?s1:s2;
	}
}

int main()
{
	char ss[128];

	gets(ss))
	str = ss;
	printf("%s\n", dfs(0, str.size()-1).c_str());
	return 0;
}