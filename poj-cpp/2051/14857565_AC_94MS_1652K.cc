#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

struct ADT {
	char str[1024];
	int time, value, n;
	bool operator < (const ADT &B) const {
		if(B.time*B.n == time*n) return value > B.value;
		return time*n > B.time*B.n;
	}
}A;

int main()
{
	int time, value, cnt;
	priority_queue<ADT> pq;
	while(scanf("%s", A.str)) {
		if(A.str[0]=='#') break;
		scanf("%d%d", &value, &time);
		A.time = time; A.value = value; A.n = 1;
		pq.push(A);
	}
	scanf("%d", &cnt);
	while(!pq.empty()) {
		ADT tmp = pq.top(); pq.pop();
		printf("%d\n", tmp.value);
		if(0==--cnt) break;
		tmp.n++; pq.push(tmp);
	}
	
	return 0;
}