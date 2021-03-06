#include <stdio.h>


int gcd(int a, int b){
	if(!b) return a;
	else return gcd(b, a%b);
}

long long lcm(int a, int b){
	return (long long)a*b/gcd(a, b);
}


int main(){
	int x, y, a, b, L;
	long long n, i;

	while(~scanf("%d%d%d%d%d", &x, &y, &a, &b, &L)){

				x %= L;  y %= L;  a %= L;  b %= L;
				
				n = lcm(L/gcd(L, a), L/gcd(L, b));
				for(i=1; i<=n; i++){
					if( (x+a*i)%L == (y+b*i)%L ) break;
				}
				if(i==n+1) printf("Impossible\n");
				else printf("%lld\n", i);

			}

	return 0;
}