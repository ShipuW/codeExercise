#include<stdio.h>
#include<string.h>
int arr[110][110];
int n;

void floyd();
void print();

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n == 0)
		{
			break;
		}
		memset(arr,0,sizeof(arr));
		int i,j;
		for(i = 1;i<=n;i++)
		{
			int num;
			scanf("%d",&num);
			for(j =1;j<=num;j++)
			{
				int a,b;
				scanf("%d%d",&a,&b);
				arr[i][a] = b;
			}
		}
		//no connection dist=99
		for(i = 1;i<=n;i++)
		{
			for(j =1;j<=n;j++)
			{
				if(i!=j && arr[i][j] == 0)
				{
					arr[i][j] = 99;
				}
			}
		}
		//update matrix with floyd
		floyd();
		//find result
		int max_min = 99;      //min dist
		int max_min_index;   //person with min dist
		for(i = 1;i<=n;i++)
		{
			int max_line = -1;     //record max dist of every person
			for(j = 1;j<=n;j++)
			{
				if(max_line<arr[i][j])
				{
					max_line = arr[i][j];
				}
			}
			if(max_min>max_line)
			{
				max_min = max_line;
				max_min_index = i;
			}
		}
		if(max_min == 99)
		{
			printf("disjoint\n");
		}
		else
		{
			printf("%d %d\n",max_min_index,max_min);
		}
	}
	return 0;
}

void floyd()
{
	int i,j,k;
	for(k =1;k<=n;k++)
	{
		for(i = 1;i<=n;i++)
		{
			for(j = 0;j<=n;j++)
			{
				if(arr[i][j]>(arr[i][k]+arr[k][j]))
				{
					arr[i][j] = arr[i][k]+arr[k][j];
				}
			}
		}
	}
}
void print()
{
	int i,j;
	for(i = 1;i<=n;i++)
	{
		for(j =1;j<=n;j++)
		{
			printf("%d     ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}