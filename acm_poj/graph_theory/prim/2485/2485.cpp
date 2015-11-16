/*fail*/

#include<stdio.h>
#include<string.h>
int arr[510][510];        //adjacent matrix
int vertex[510];          //vertex array
int N;

int prim();
int check();

int main()
{
	int i,j;
	int T;
	scanf("%d",&T);
	for(i = 0;i<T;i++)
	{
		memset(vertex,0,sizeof(vertex));
		scanf("%d",&N);
		//init matrix
		for(i = 1;i<=N;i++)
		{
			for(j = 1;j<=N;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		printf("%d\n",prim());
	}
	return 0;
}

int prim()
{
	int i,j;
	int max_distance = 0;
	vertex[1] = 1;
	while(check())
	{
		int point;
		int min;
		min = 65537;
		for(i = 1;i<=N;i++)
		{
			if(vertex[i] == 0)
			{
				for(j = 1;j<=N;j++)
				{
					if(vertex[j] == 1)
					{
						if(min>arr[i][j])
						{
							min = arr[i][j];
							point = i;
						}
					}
				}
			}
		}
		if(max_distance<min)
		{
			max_distance = min;
		}
		vertex[point] = 1;
	}
	return max_distance;
}

int check()
{
	int i;
	for(i = 1;i<=N;i++)
	{
		if(vertex[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}
