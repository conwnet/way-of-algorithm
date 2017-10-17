#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int d[3000][3000];

int main()
{
	int N, i, j;
	char str[8000];
	
	scanf("%d", &N);
	scanf("%s", str+1);
	memset(d, 0, sizeof(d));
	for (i=N; i>0; i--) {
		for (j=i; j<=N; j++) {
			if (str[i] == str[j]) {
				d[i][j] = d[i+1][j-1];
			} else {
				d[i][j] = min(d[i+1][j], d[i][j-1])+1;
			}
		}
	}
	printf("%d\n", d[1][N]);

	return 0;
}