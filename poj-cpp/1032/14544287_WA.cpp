#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/**
int dp[1024][1024], path[1024];

int dfs(int a, int n)
{
	if(dp[a][n]) return dp[a][n];
	if(a==0) return 1;
	int ans = 0;
	//path[num] = a;
	for(int i=n; i>0; i--) {
		if(a-i<0) continue;
		int t = dfs(a-i, i-1);
		if(i*t > ans) {
			ans = i*t;
			//path[num] = i;
		}
	}
	return dp[a][n] = ans;
}
*/

vector<int> ans;

int main()
{
	int n;

	scanf("%d", &n);
	for(int i=2; n>i; n-=i++) {
		ans.push_back(i);
	}
	for(int i=ans.size()-1; n>0; i--, n--)
		ans[i] += 1;
	printf("%d", ans[0]);
	for(int i=1; i<ans.size(); i++)
		printf(" %d", ans[i]);

	return 0;
}
