#include <stdio.h>
#include <string.h>

int dp[21][16001], N, M;
int pos[21], wei[21];

int main()
{
	memset(dp, 0, sizeof(dp));
	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++)
		scanf("%d", &pos[i]);
	for(int i=1; i<=M; i++)
		scanf("%d", &wei[i]);
	dp[0][7500] = 1;
	for(int i=1; i<=M; i++) {
		for(int j=0; j<15001; j++) {
			for(int k=1; k<=N; k++) {
				dp[i][j+wei[i]*pos[k]] += dp[i-1][j];
			}
		}
	}
	printf("%d\n", dp[M][7500]);
	
	return 0;
}