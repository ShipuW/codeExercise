#include<stdio.h>
int n;
int arr[100010];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		int count_xiaoyu = 0;
		int can = 1;
		int index = n-1;
		for(i=1;i<n;i++)
		{
			if(arr[i]<arr[i-1])
			{
				count_xiaoyu++;
				if(count_xiaoyu == 1)
				{
					index = i-1;
				}
			}				
			if(count_xiaoyu>1)
			{
				can = 0;
				break;
			}
		}
		if(count_xiaoyu == 1 && arr[n-1] > arr[0])
		{
			can = 0;
		}
		if(can)
		{
			printf("%d\n",n-1-index);
		}
		else
		{
			printf("-1\n");
		}
	}
}