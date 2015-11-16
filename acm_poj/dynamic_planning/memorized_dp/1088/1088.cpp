#include<stdio.h>
#include<string.h>

int dp[105][105];
int arr[105][105];
int r,c;
int solve(int x,int y);

int main()
{
	while(scanf("%d%d",&r,&c)!=EOF)
	{
		int i,j;
		memset(dp,0,sizeof(dp));
		for(i = 1;i<=r;i++)
		{
			for(j = 1;j<=c;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		int max = 0;
		for(i = 1;i<=r;i++)
		{
			for(j = 1;j<=c;j++)
			{
				int temp = solve(i,j);
				max = max>temp?max:temp;
			}
		}
		printf("%d\n",max);
	}
	return 1;
}
int solve(int x,int y)
{
	if(dp[x][y])
	{
		return dp[x][y];
	}
	int max = 0;
	if(y<c && arr[x][y]>arr[x][y+1])
	{
		int temp = solve(x,y+1);
		max = max>temp?max:temp;
	}
	if(x<r && arr[x][y]>arr[x+1][y])
	{
		int temp = solve(x+1,y);
		max = max>temp?max:temp;
	}
	if(y>1 && arr[x][y]>arr[x][y-1])
	{
		int temp = solve(x,y-1);
		max = max>temp?max:temp;
	}
	if(x>1 && arr[x][y]>arr[x-1][y])
	{
		int temp = solve(x-1,y);
		max = max>temp?max:temp;
	}
	return dp[x][y] = max+1;
}