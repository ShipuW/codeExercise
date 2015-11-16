#include<stdio.h>
#include<string.h>

int N,M;
int i,j;
int value[510];
int need[510];
int f[100010];

int max(int a,int b);

int main()
{
	memset(f,0,sizeof(f));
	scanf("%d %d",&N,&M);
	for(i =1;i<=N;i++)
	{
		scanf("%d %d",&need[i],&value[i]);
	}
	for(i = 1;i<=N;i++)
	{
		for(j = M;j>=need[i];j--)
		{
			f[j] = max(f[j],f[j-need[i]]+value[i]);
		}
	}
	printf("%d",f[M]);
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}
