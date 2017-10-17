
#include <cstdio>
#include <cstdlib>
#define N 333333
#define P 17

int n;
long long a[N];

void Swap(int i,int j)
{
	long long t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int Partition(int p,int r)
{
	//int len = r - p + 1;
	//int random = ((rand()*P)%len) + p;
	//Swap(random,r);
	int i,j;
	i = p - 1;
	for(j=p;j<r;j++)
	{
		if(a[j]<=a[r])
		{
			i++;
			Swap(i,j);
		}
	}
	i++;
	Swap(i,j);
	return i;
}

long long Select(int p,int r,int k)
{
	while(p<r)
	{
		int q = Partition(p,r);
		int l = q - p + 1;
		if(k<l)
		{
			return a[k];
		}
		else if(k>l)
		{
			p = q + 1;
			k -= l;
		}
		else
		{
			return a[q];
		}
	}
	return a[p];
}

long long Kth(int k)
{
	return Select(1,n,k);
}

int main()
{
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	double median;
	if(n%2)
	{
		median = Kth((n+1)/2) * 1.0;
	}
	else
	{
		median = (Kth(n/2) + Kth(n/2+1)) / 2.0;
	}
	printf("%.1lf\n",median);
}
