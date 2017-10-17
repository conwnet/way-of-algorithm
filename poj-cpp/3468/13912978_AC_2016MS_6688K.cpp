#include<iostream>
#include<stdio.h>
using namespace std;
#define MAXSIZE 100000
int total_edge,val[MAXSIZE+1];

struct node
{
	long long total;
	int left;
	int right;
	long long mark ;
}tree[MAXSIZE*3];

long long create(int root,int left,int right)
{
	tree[root].mark=0;
	tree[root].left=left;
	tree[root].right=right;
	if(left==right)
	return tree[root].total=val[left];
	int middle=(left+right)/2;
	return tree[root].total=create(2*root,left,middle)+create(2*root+1,middle+1,right);
}
void updata_mark(int root)
{
	if(tree[root].mark)
	{
		tree[root].total+=tree[root].mark*(tree[root].right-tree[root].left+1);
		if(tree[root].left!=tree[root].right)
		{
			tree[root*2].mark+=tree[root].mark;
			tree[root*2+1].mark+=tree[root].mark;
		}
		tree[root].mark=0;
	}
}
long long calculate(int root,int left,int right)
{
	updata_mark(root);
	if(tree[root].left>right||tree[root].right<left)
		return 0 ;
	if(left<=tree[root].left&&tree[root].right<=right)
		return tree [root].total;
	return calculate(2*root,left,right)+calculate(2*root+1,left,right);
}
long long updata(int root,int left,int right,int val)
{
	updata_mark(root);
	if(tree[root].left>right||tree[root] .right<left)
		return tree[root].total;
	if(left<=tree[root].left&&tree[root].right<=right)
	{
		tree[root].mark=val;
		updata_mark(root);
		return tree[root].total;
	}
	return tree[root].total=updata(2*root,left,right,val)+updata(2*root+1,left,right,val);
}

int main()
{
	int n,q;
	while(~scanf("%d%d",&n,&q))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		create(1,1,n);
		char op;
		for(int i=0;i<q;i++)
		{
			scanf("\n%c",&op);
			if(op=='Q')
			{
				int a,b;
				scanf("%d %d",&a,&b);
				printf("%I64d\n",calculate(1,a,b));
			}
			else
			{
				int a,b ,c;
				scanf("%d%d%d",&a,&b,&c);
				updata(1,a,b,c);
			}
		}
	}
}