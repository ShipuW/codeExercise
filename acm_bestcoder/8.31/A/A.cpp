#include<stdio.h>
#include<string.h>
int arr_1[100010];
int arr_2[100010];
int n;
int i,j;
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		memset(arr_1,0,sizeof(arr_1));
		for(i = 1;i<=n;i++)
		{
			scanf("%d",&arr_2[i]);
		}
		for(i = 1;i<=n;i++)
		{
			if(arr_1[i] == 0)
			{
				arr_1[i] = 1;
				int ori = i;
				printf("(%d",i);
				int new_i = arr_2[i];
				while(new_i != i)
				{
					arr_1[new_i] = 1;
					printf(" %d",new_i);
					new_i = arr_2[new_i];
				}
				printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}