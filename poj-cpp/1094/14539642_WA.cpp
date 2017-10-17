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
	int _deg[30], tmp, vst[30];
	memcpy(_deg, deg, sizeof(deg));
	memset(vst, 0, sizeof(vst));
	ans.clear();
	for(int i=0; i<N; i++) {
		int cnt = 0;
		for(int j=0; j<N; j++) {
			if(!_deg[j] && !vst[j]) {
				cnt++;
				tmp = j;
				vst[j] = 1;
			}
		}
		//printf("----------%d\n", cnt);
		if(cnt>1) return 0;
		if(!cnt) return -1;
		ans.push_back(tmp);
		for(int j=0; j<G[tmp].size(); j++) {
			if(_deg[G[tmp][j]]) {
				_deg[G[tmp][j]]--;
			}
		}
	}
	return 1;
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
			} else {
				G[b].push_back(a);
				deg[a]++;
			}
			int t = top_sort();
			if(t==1) {
				printf("Sorted sequence determined after %d relations: ", i);
				for(i=0; i<ans.size(); i++) printf("%c", ans[i]+'A');
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




