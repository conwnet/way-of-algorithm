#include <stdio.h>
#include <string.h>

int main()
{
	char str[50];

	while(scanf("%s", str)) {
		if(!strcmp(str, "0")) break;
		int l = strlen(str);
		int ans = 0;
		for(int i=0; i<l; i++) {
			ans += ((1<<(l-i)) - 1) * (str[i]-'0');
		}
		printf("%d\n", ans);
	}

	return 0;
}
