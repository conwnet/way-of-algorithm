#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Pos {
	int r, c;
	Pos(int a, int b):
		r(a), c(b) {}
	Pos() {}
};

typedef pair<int, int> P;

int fact[10];
P n_per[400000];
int path[10000];

void get_fact()
{
	for(int n=0; n<10; n++) {
		int s = 1;
		for(int i=n; i>1; i--)
			s *= i;
		fact[n] = s;
	}
}

int per2n(char *str)
{
	int sum = 0;

	for(int i=0; i<8; i++) {
		int t = 0;
		for(int j=i+1; j<9; j++)
			if(str[j]<str[i])
				t++;
		sum += t*fact[8-i];
	}

	return sum;
}

void n2per(int n, char *str)
{
	int i, j, k;
	int used[10] = {0};

	for(i=0; i<9; i++) {
		for(j=(8-i); j>=0; j--) {
			if(n>=j*fact[8-i]) break;
		}
		n -= j*fact[8-i];
		j++;
		for(k=0; j>0; k++) {
			if(used[k]) continue;
			else j--;
		}
		used[k-1] = 1;
		str[i] = k-1+'0';
	}
	str[9] ='\0';
}

queue<int> que;

int move(int n, int op)
{
	char per[10];
	int k;
	
	n2per(n, per);
	for(k=0; per[k]!='0'; k++);
//	printf("%s  %d\n", per, k);
	if(op==1) {
		if(k-3<0) return -1;
		int t = per[k-3];
		per[k-3] = per[k];
		per[k] = t;
	} else if(op==2) {
		if(k+3>8) return -1;
		int t= per[k+3];
		per[k+3] = per[k];
		per[k] = t;
	} else if(op==3) {
		if(k%3==0) return -1;
		int t = per[k-1];
		per[k-1] = per[k];
		per[k] = t;
	} else if(op==4) {
		if(k%3==2) return -1;
		int t = per[k+1];
		per[k+1] = per[k];
		per[k] = t;
	}
	return per2n(per);
}

int main()
{
	char per[10];
	int cnt = 0, s, ans;
	
	get_fact();
	//printf("%d\n", per2n("123456780"));
	while(1) {
		int ch = getchar();
		if(ch==-1) break;
		if(ch=='\n') break;
		if(ch==' ') continue;
		if(ch=='x') {
			ch = '0';
		}
		per[cnt++] = ch;
	}
	per[cnt] = '\0';
	s = per2n(per);
	ans = -1;
	n_per[s].first = -1;
	que.push(s);
	while(!que.empty()) {
		int tmp = que.front(); que.pop();
		//printf("%d \n", tmp);
		if(tmp==46233) {
			ans = 1;
			break;
		}
		for(int i=1; i<=4; i++) {
			int t = move(tmp, i);
			if(t==-1) continue;
			if(n_per[t].first) continue;
			n_per[t].first = i; n_per[t].second = tmp;
			//printf("%d\n", i);
			que.push(t);
		}
	}
	if(-1 == ans) printf("unsolvable\n");
	else {
		int cnt = 0;
		for(int i=46233; n_per[i].first!=-1; i=n_per[i].second)
			path[cnt++] = n_per[i].first;
		for(int i=cnt-1; i>=0; i--) {
			switch(path[i]) {
				case 1: putchar('u'); break;
				case 2: putchar('d'); break;
				case 3: putchar('l'); break;
				case 4: putchar('r'); break;
			}
		}
	}
	printf("\n");
	
	return 0;
}



















