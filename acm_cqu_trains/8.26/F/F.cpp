#include<stdio.h>

int dis[110];
int n;
int s,t;
int i,j;

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		for(i = 1;i<=n;i++)
		{
			scanf("%d",&dis[i]);
		}
		scanf("%d%d",&s,&t);
		int distance_1 = 0;
		int distance_2 = 0;
		int temp_s = s,temp_t = t;
		while(temp_s != temp_t)
		{
			distance_1 += dis[temp_s];
			temp_s++;
			if(temp_s > n)
			{
				temp_s = 1;
			}
		}
		temp_s = s;temp_t = t;
		while(temp_s != temp_t)
		{
			distance_2 += dis[temp_t];
			temp_t++;
			if(temp_t > n)
			{
				temp_t = 1;
			}
		}
		int min_distance = distance_1 < distance_2 ? distance_1 : distance_2;
		printf("%d\n",min_distance);
	}
	return 0;
}