#include<stdio.h>
#include<string.h>

int N,M;
int i,j,k;
int arr[510][100010];
int value[510];
int need[510];

int max(int a,int b);

int main()
{
	memset(arr,0,sizeof(arr));
	scanf("%d %d",&N,&M);
	for(i = 1;i<=N;i++)
	{
		scanf("%d %d",&need[i],&value[i]);
	}
	for(i = 1;i<=N;i++)
	{
		for(j = 1;j<=M;j++)
		{
			for(k = 0;k<=j/need[i];k++)
			{
				arr[i][j] = max(arr[i-1][j],arr[i-1][j-need[i]*k]+value[i]*k);
			}
		}
	}
	printf("%d",arr[N][M]);
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}