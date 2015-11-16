#include<stdio.h>
int N,M;
int arr[1010];
void merge(int a,int b);
int find(int a);
void init();
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		if(N == 0)
		{
			break;
		}
		scanf("%d\n",&M);
		init();
		while(M--)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			merge(a,b);
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
		printf("%d\n",count-1);
	}
	return 1;
}
void merge(int a,int b)
{
	int ux = find(a);
	int uy = find(b);
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
	if(arr[a] != a)
	{
		arr[a] = find(arr[a]);
	}
	return arr[a];
}
void init()
{
	int i;
	for(i = 1;i<=N;i++)
	{
		arr[i] = i;
	}
}