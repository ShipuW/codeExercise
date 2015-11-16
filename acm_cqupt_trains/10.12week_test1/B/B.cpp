#include<stdio.h>
int home[110];
int guest[110];
int n;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		int i,j;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&home[i],&guest[i]);
		}
		int count = 0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(home[i] == guest[j])
				{
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}