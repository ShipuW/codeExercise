#include<stdio.h>
#include<stdlib.h>
int adjacency_matrix[110][110];           //adjacent matrix
int vertex[110];                  //vertex array
int distance[110];                //distance between vertex and other point
int n;
const int MAX = 999999999;

int not_finished();
void print();

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		//getchar();
		int i,j;
		char temp_str[100];
		adjacency_matrix[1][1] = 0;
		//1 means done, 0 means not 
		vertex[1] = 1;
		for(i = 2;i<=n;i++)
		{
			vertex[i] = 0;	      //not done except 1
		}
		for(i = 2;i<=n;i++)
		{
			adjacency_matrix[i][i] = 0;
			//init
			for(j = 1;j<i;j++)
			{
				scanf("%s",temp_str);
				if(temp_str[0] == 'x')            //notice!
				{
					adjacency_matrix[i][j] = MAX;
					adjacency_matrix[j][i] = MAX;
				}
				else
				{
					int temp_int = atoi(temp_str);
					adjacency_matrix[i][j] = temp_int;
					adjacency_matrix[j][i] = temp_int;
				}
			}
		}
		//init distance array
		distance[1] = 0;
		for(i = 2;i<=n;i++)
		{
			distance[i] = adjacency_matrix[i][1];
		}
		//begin dij algorithm
		while(not_finished())
		{
			//find a point and merge
			int shortest_distance = MAX;       //shortest distance
			int shortest_vecter;             //point with shorest dist
			for(i = 2;i<=n;i++)
			{
				if(vertex[i] == 0)
				{
					if(distance[i]<shortest_distance)
					{
						shortest_distance = distance[i];
						shortest_vecter = i;
					}
				}
			}
			vertex[shortest_vecter] = 1;
			//update distance ;
			for(i = 2;i<=n;i++)
			{
				if(vertex[i] == 0)
				{
					shortest_distance = MAX;
					for(j = 1;j<=n;j++)
					{
						if(vertex[j] == 1 && (adjacency_matrix[i][j]+distance[j])<shortest_distance)
						{
							shortest_distance = adjacency_matrix[i][j]+distance[j];
							shortest_vecter = i;
						}
					}
					distance[shortest_vecter] = shortest_distance;
				}
			}
		}
		//find max dist
		int max_distance = distance[1];
		for(i = 2;i<=n;i++)
		{
			if(distance[i]>max_distance)
			{
				max_distance = distance[i];
			}
		}
		printf("%d\n",max_distance);
	}
	return 0;
}

int not_finished()
{
	int i;
	for(i = 1;i<=n;i++)
	{
		if(vertex[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}

void print()
{
	int i;
printf("\n");
printf("vertex\n");
	for(i = 1;i<=n;i++)
	{
		printf("%d ",vertex[i]);
	}
printf("\n");
printf("distance\n");
	for(i = 1;i<=n;i++)
	{
		printf("%d ",distance[i]);
	}
printf("\n");
printf("\n\n");
}

			/*
			for(i = 2;i<=n;i++)
			{
				if(vertex[i] == 0)
				{
					for(j = 1;j<=n;j++)
					{
						if(vertex[j] == 1 && (adjacency_matrix[i][j]+distance[j])<shortest_distance)
						{
							shortest_distance = adjacency_matrix[i][j]+distance[j];
							shortest_vecter = i;
						}
					}
				}
			}
			vertex[shortest_vecter] = 1;
			distance[shortest_vecter] = shortest_distance;
			*/
			/*
			//¸üÐÂdistance±í;
			for(i = 2;i<=n;i++)
			{
				if(vertex[i] == 0)
				{
					shortest_distance = MAX;
					for(j = 1;j<=n;j++)
					{
						if(vertex[j] == 1 && (adjacency_matrix[i][j])<shortest_distance)
						{
							shortest_distance = adjacency_matrix[i][j];
							shortest_vecter = i;
						}
					}
					distance[shortest_vecter] = shortest_distance;
				}
			}
			*/