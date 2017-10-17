#include <stdio.h>


long long gcd(long long a, long long b){
	if(!b) return a;
	else return gcd(b, a%b);
}

long long lcm(long long a, long long b){
	return a*b/gcd(a, b);
}


int main(){
	long long x, y, a, b, L, n, i;

	while(~scanf("%lld%lld%lld%lld%lld", &x, &y, &a, &b, &L)){

				x %= L;  y %= L;  a %= L;  b %= L;
				if(x==y){
					printf("0\n");
					continue;
				}
				n = lcm(L/gcd(L, a), L/gcd(L, b));
				for(i=1; i<=n; i++){
					if( (x+a*i)%L == (y+b*i)%L ) break;
				}
				if(i==n+1) printf("Impossible\n");
				else printf("%lld\n", i);

			}

	return 0;
}