#include<stdio.h>
int T;
int N;
int i;
int arr[1010];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int mark = 1;
		for(i = 1;i<=N;i++)
		{
			scanf("%d",&arr[i]);
		}
		if(N == 1)
		{
			printf("Yes\n");
			continue;
		}
		if(arr[1] == 1)
		{
			for(i = 2;i<=N-1;i++)
			{
				if(arr[i]!=1)
				{
					break;
				}
				else
				{
					mark = (mark == 1)?0:1;
				}
			}
			if(mark == 1)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");	
			}
		}
		else
		{
			printf("Yes\n");
		}
	}
	return 1;
}