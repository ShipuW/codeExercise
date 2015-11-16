#include<stdio.h>
int arr[110][110];
//int auxi[110][110];

int max(int a,int b);

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i = 1;i<=n;i++)
		{
			for(j = 1;j<=i;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		for(i = n-1;i>=1;i--)
		{
			for(j = 1;j<=i;j++)
			{
				arr[i][j]+=max(arr[i+1][j],arr[i+1][j+1]);
			}
		}
		printf("%d\n",arr[1][1]);
	}
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}