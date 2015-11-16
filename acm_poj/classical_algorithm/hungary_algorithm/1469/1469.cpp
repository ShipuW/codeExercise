#include<stdio.h>
#include<string.h>

int p,n;
int visit[310];
int match[310];
int graph[110][310];
int i,j;
int flag;

int hungary();
int dfs(int u);

int main()
{
	int time;
	scanf("%d",&time);
	while(time--)
	{
		memset(match,-1,sizeof(match));
		memset(graph,0,sizeof(graph));
		flag = 0;
		scanf("%d%d",&p,&n);
		for(i = 1;i<=p;i++)
		{
			int num;
			scanf("%d",&num);
			if(num == 0)
			{
				flag = 1;
			}
			while(num--)
			{
				int temp;
				scanf("%d",&temp);
				graph[i][temp] = 1;
			}
		}
		if(flag)
		{
			printf("NO\n");
		}
		else
		{
			int maximum_matching = hungary();
			if(maximum_matching == p)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}

int hungary()
{
	int count = 0;
	for(i = 1;i<=p;i++)
	{
		memset(visit,0,sizeof(visit));
		if(dfs(i))
		{
			count++;
		}
	}
	return count;
}

int dfs(int u)
{
	for(int k = 1;k<=n;k++)
	{
		if(graph[u][k] && !visit[k])
		{
			visit[k] = 1;
			if(match[k] == -1 || dfs(match[k]))
			{
				match[k] = u;
				return true;
			}
		}
	}
	return false;
}
