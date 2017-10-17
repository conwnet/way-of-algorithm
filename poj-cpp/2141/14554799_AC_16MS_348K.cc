#include <stdio.h>


int main()
{
	char maps[27];
	scanf("%s", maps);
	int ch;
	getchar();
	while((ch=getchar())!=EOF) {
		if(ch<='Z' && ch>='A') {
			putchar(maps[ch-'A']-'a'+'A');
		} else if(ch<='z' && ch>='a') {
			putchar(maps[ch-'a']);
		} else 
			putchar(ch);
	}

	return 0;
}