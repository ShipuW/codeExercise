#include<stdio.h>

typedef struct restuarant
{
	int f;
	int t;
	int joy;
}rest;

rest r[10010];
int n,k;
int i,j;

int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(i = 0;i<n;i++)
		{
			scanf("%d%d",&r[i].f,&r[i].t);
			if(r[i].t <= k)
			{
				r[i].joy = r[i].f;
			}
			else
			{
				r[i].joy = r[i].f - (r[i].t - k);
			}
		}
		int max_joy = r[0].joy;
		for(i = 1;i<n;i++)
		{
			if(r[i].joy >= max_joy)
			{
				max_joy = r[i].joy;
			}
		}
		printf("%d\n",max_joy);
	}
	return 0;
}