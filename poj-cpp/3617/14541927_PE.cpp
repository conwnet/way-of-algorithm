#include <stdio.h>
#include <string.h>

char str[2048];

int judge(int s, int t)
{
	while(s<=t && str[s]==str[t]) {
		s++; t--;
	}
	return str[s]<str[t];
}

int main()
{
	int N;

	scanf("%d", &N);
	for(int i=0; i<N; i++) {
		getchar();
		str[i] = getchar();
	}
	int s = 0;
	int t = N-1;
	while(s<=t) {
		if(str[s]<str[t]) {
			putchar(str[s]);
			s++;
		} else if(str[t]>str[s]) {
			putchar(str[t]);
			t--;
		} else {
			if(judge(s, t)) {
				putchar(str[s]);
				s++;
			} else {
				putchar(str[t]);
				t--;
			}
		}
	}
	printf("\n");

	return 0;
}