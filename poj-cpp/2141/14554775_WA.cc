#include <stdio.h>


int main()
{
	char maps[27];
	scanf("%s", maps);
	int ch;
	getchar();
	while((ch=getchar())!=EOF) {
		if(ch==' ') putchar(' ');
		else if(ch<='Z' && ch>'A') {
			putchar(maps[ch-'A']-'a'+'A');
		} else {
			putchar(maps[ch-'a']);
		}
	}

	return 0;
}