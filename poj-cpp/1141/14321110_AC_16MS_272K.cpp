#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int dp[128][128],  pos[128][128];
char str[128];

int dfs(int s, int e)
{
	int ans = 99999;

	if(s>e) return 0;
	if(s==e) return 1;
	if(dp[s][e]!=-1) return dp[s][e];
	if((str[s]=='(' && str[e]==')') || (str[s]=='[' && str[e]==']'))
		ans = dfs(s+1, e-1);
	for(int i=s; i<e; i++) {
		int t = dfs(s, i) + dfs(i+1, e);
		if(t<ans) {
			ans = t;
			pos[s][e] = i;
		}
	}

	return dp[s][e] = ans;
}

int print(int s, int e)
{
	if(s>e) return 0;
	if(s==e) {
		if(str[s]=='(' || str[s]==')') printf("()");
		else printf("[]");
		return 0;
	}
	if(pos[s][e]!=-1) {
		print(s, pos[s][e]);
		print(pos[s][e]+1, e);
	} else {
		putchar(str[s]);
		print(s+1, e-1);
		putchar(str[e]);
	}
	return 0;
}

int main()
{
	memset(pos, -1, sizeof(pos));
	memset(dp, -1, sizeof(dp));
	gets(str);
	dfs(0, strlen(str)-1);
	print(0, strlen(str)-1);
	printf("\n");

	return 0;
}

