#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int deg[30];
vector<int> G[30], ans;

int top_sort()
{
	int _deg[30], tmp, flag=1;
	memcpy(_deg, deg, sizeof(deg));
	ans.clear();
	for(int i=0; i<N; i++) {
		int cnt = 0;
		for(int j=0; j<N; j++) {
			if(!_deg[j]) {
				cnt++;
				tmp = j;
			}
		}
		//printf("----------%d\n", cnt);
		if(cnt>1) flag = 0;
		if(!cnt) return -1;
		ans.push_back(tmp);
		_deg[tmp] = -1;
		for(int j=0; j<G[tmp].size(); j++) {
			_deg[G[tmp][j]]--;
		}
	}
	return flag;
}

int main()
{
	char str[10];

	while(scanf("%d%d", &N, &M)) {
		if(!M && !N) break;
		memset(deg, 0, sizeof(deg));
		for(int i=0; i<N; i++) G[i].clear();
		int ok = 0;
		for(int i=1; i<=M; i++) {
			scanf("%s", str);
			if(ok) continue;
			int a = str[0]-'A';
			int b = str[2]-'A';
			if('<'==str[1]) {
				G[a].push_back(b);
				deg[b]++;
			}
			int t = top_sort();
			if(t==1) {
				printf("Sorted sequence determined after %d relations: ", i);
				for(int k=0; k<ans.size(); k++) printf("%c", ans[k]+'A');
				printf(".\n");
				ok = 1;
			} else if(t==-1) {
				printf("Inconsistency found after %d relations.\n", i);
				ok = 1;
			}
		}
		if(!ok) printf("Sorted sequence cannot be determined.\n");
	}

	return 0;
}



