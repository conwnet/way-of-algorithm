#include <cstdio>
#include <algorithm>

using namespace std;

int num[1100000];

int main(){
	int n, i;
	while(~scanf("%d", &n)){
		for(i=0; i<n; i++){
			scanf("%d", &num[i]);
		}
		sort(num, num+n);
		printf("%d\n", num[n/2]);
	}
	return 0;
}