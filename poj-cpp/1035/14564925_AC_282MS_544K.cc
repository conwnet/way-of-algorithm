#include <stdio.h>
#include <string.h>

char dic[10001][20];

int add(int n, char *str)
{
	int i, j = 0, ok = 0;
	for(i=0; dic[n][i] && str[j]; i++) {
		if(dic[n][i]!=str[j]) {
			if(!ok) {
				ok = 1;
				continue;
			}
			break;
		}
		j++;
	}
	if(!dic[n][i] && !str[j]) return 1;
	if(!ok && !dic[n][i+1] && !str[j]) return 1;
	return 0;
}

int del(int n, char *str)
{
	int i, j = 0, ok = 0;
	for(i=0; dic[n][i] && str[j]; j++) {
		if(dic[n][i]!=str[j]) {
			if(!ok) {
				ok = 1;
				continue;
			}
			break;
		}
		i++;
	}
	if(!dic[n][i] && !str[j]) return 1;
	if(!ok && !dic[n][i] && !str[j+1]) return 1;
	return 0;
}

int rep(int n, char *str)
{
	int i, j = 0, ok = 0;
	for(i=0; dic[n][i] && str[j]; i++, j++) {
		if(dic[n][i]!=str[j]) {
			if(!ok) {
				ok = 1;
				continue;
			}
			break;
		}
	}
	if(!dic[n][i] && !str[j]) return 1;
	return 0;
}

void judge(int n, char *str)
{
	if(add(n, str) || del(n, str) || rep(n, str))
		printf(" %s", dic[n]);
}

int N;

int main()
{
	N = 0;
	while(scanf("%s", dic[N])) {
		if(!strcmp(dic[N], "#"))
			break;
		N++;
	}
	char str[20];
	while(scanf("%s", str)) {
		if(!strcmp(str, "#"))
			break;
		int i;
		for(i=0; i<N; i++) {
			if(!strcmp(dic[i], str))
				break;
		}
		if(i!=N) {
			printf("%s is correct\n", str);
			continue;
		}
		printf("%s:", str);
		for(i=0; i<N; i++)
			judge(i, str);
		printf("\n");
	}
	return 0;
}



