#include <stdio.h>
#include <string.h>

int num[80000000];

void getnum();

int main(){
	int s, e, i, max;

	getnum();
	while(~scanf("%d%d", &s, &e)){
if(s>e) s^=e^=s^=e;
		for(i=s, max=0; i<=e; i++){
			if(num[i]>max) max = num[i];
		}
		printf("%d %d %d\n", s, e, max);
	}

	return 0;
}

void getnum(){
	int i, j, cnt, n;

	memset(num, 0, 44000);

	num[1] = 1;
	for(i=1; i<11000; i++){
		n = i;
		cnt = 0;
		while(1){
			if(num[n]){
				num[i] = cnt+num[n];
				break;
			}
			if(n%2) n = 3*n+1;
			else n = n/2;
			cnt ++;
		}

	}
}