#include <stdio.h>
#include <string.h>

int maps[105][105];

int main()
{
	int T, a, b, c;
	char cmd[10];
	scanf("%d", &T);
	while(T--) {
		scanf("%s%d%d%d", cmd, &a, &b, &c);
		if(cmd[0]=='W') {
			for(int i=a; i<a+c; i++)
				for(int j=b; j<b+c; j++)
					maps[i][j] = 0;
		} else if(cmd[0]=='B') {
			for(int i=a; i<a+c; i++)
				for(int j=b; j<b+c; j++)
					maps[i][j] = 1;
		} else {
			int ans = 0;
			for(int i=a; i<a+c; i++)
				for(int j=b; j<b+c; j++)
					if(maps[i][j]) ans++;
			printf("%d\n", ans);
		}
	}

	return 0;
}
