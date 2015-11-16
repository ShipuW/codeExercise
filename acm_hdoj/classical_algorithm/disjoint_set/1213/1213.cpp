#include<stdio.h>
int arr[1010];
int T;
int M,N;
void merge(int a,int b);
int find(int a);
void init();
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&M);
		init();
		while(M--)
		{
			int A,B;
			scanf("%d%d",&A,&B);
			merge(A,B);
		}
		int i;
		int count = 0;
		for(i = 1;i<=N;i++)
		{
			if(arr[i] == i)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 1;
}
void init()
{
	int i;
	for(i = 1;i<=N;i++)
	{
		arr[i] = i;
	}
}
void merge(int x,int y)
{
	int ux = find(x);
	int uy = find(y);
	if(ux == uy)
	{
		return;
	}
	if(ux<uy)
	{
		arr[uy] = ux;
	}
	else
	{
		arr[ux] = uy;
	}
}
int find(int a)
{
	if(arr[a]!=a)
	{
		arr[a] = find(arr[a]);
	}
	return arr[a];
}