#include <stdio.h>

int main()
{
	int cnt, n, T;

	scanf("%d", &T);
	getchar();
	while(T--) {
		n = getchar();
		cnt = 1;
		while(1) {
			int ch = getchar();
			if(ch!=n) {
				printf("%d%c", cnt, n);
				n = ch;
				cnt = 1;
			} else {
				cnt ++;
			}
			if(ch=='\n') break;
		}
		printf("\n");
	}

	return 0;
}

