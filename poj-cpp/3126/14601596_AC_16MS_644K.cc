#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 10000;

int isp[maxn];

void get_prime()
{
	int n = sqrt(maxn)+0.5;
	memset(isp, -1, sizeof(isp));
	isp[0] = isp[1] = 0;
	for(int i=2; i<=n; i++) {
		if(!isp[i]) continue;
		for(int j=i*i; j<maxn; j+=i)
			isp[j] = 0;
	}
}

typedef pair<int, int> P;
int vst[maxn];

int main()
{
	int n, m, T;
	queue<P> que;

	get_prime();
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(vst, 0, sizeof(vst));
		while(!que.empty())
			que.pop();
		int ok = 0;
		que.push(P(n, 0));
		vst[n] = 1;
		while(!que.empty()) {
			P tmp = que.front();
			que.pop();
			if(tmp.first==m) {
				ok = 1;
				printf("%d\n", tmp.second);
				break;
			}
			int t;
			for(int i=1; i<10; i++) {
				t = tmp.first;
				if(t%10 + i >=10)
					t -= 10;
				if(t+i>=1000 && !vst[t+i] && isp[t+i]) {
					vst[t+i] = tmp.first;
					que.push(P(t+i, tmp.second+1));
				}
				t = tmp.first;
				if((t/10)%10 + i >= 10)
					t -= 100;
				if(t+i*10>=1000 && !vst[t+i*10] && isp[t+i*10]) {
					vst[t+i*10] = tmp.first;
					que.push(P(t+i*10, tmp.second+1));
				}
				t = tmp.first;
				if((t/100)%10 + i >= 10)
					t -= 1000;
				if(t+i*100>=1000 && !vst[t+i*100] && isp[t+i*100]) {
					vst[t+i*100] = tmp.first;
					que.push(P(t+i*100, tmp.second+1));
				}
				t = tmp.first;
				if((t/1000)%10 + i >= 10)
					t -= 10000;
				if(t+i*1000>=1000 && !vst[t+i*1000] && isp[t+i*1000]) {
					vst[t+i*1000] = tmp.first;
					que.push(P(t+i*1000, tmp.second+1));
				}
			}
		}
		if(!ok) printf("Impossible\n");
	}

	return 0;
}






