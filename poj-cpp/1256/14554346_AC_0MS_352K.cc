#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool is_upper(char ch)
{
	if(ch<='Z' && ch>='A')
		return true;
	return false;
}

char lower(char ch)
{
	return ch-'A'+'a';
}

struct Char {
	char c;
	Char(char c):
		c(c) {};
	Char() {}
	bool operator < (const Char &B) const {
		if(is_upper(c) && is_upper(B.c))
			return c < B.c;
		if(is_upper(c)) {
			char ch = lower(c);
			return ch==B.c ? 1 : ch<B.c;
		}
		if(is_upper(B.c)) {
			char ch = lower(B.c);
			return ch==c ? 0 : c<ch;
		}
		return c<B.c;
	}
};

Char str[15];

int main()
{
	int T, ch;

	scanf("%d", &T);
	getchar();
	while(T--) {
		int l = 0;
		while(ch=getchar()) {
			if(ch=='\n') break;
			str[l++].c = ch;
		}
		sort(str, str+l);
		do {
			for(int i=0; i<l; i++)
				putchar(str[i].c);
			putchar('\n');
		} while(next_permutation(str, str+l));
	}

	return 0;
}






