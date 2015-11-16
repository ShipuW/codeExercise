#include<stdio.h>
#include<iostream>
#include<queue>
int map[110][110];           //原地图
int way[110][110];           //辅助地图用来标明方向
int visit[110][110];         //标记是否走过
int N,M;
int escape;        //标记是否能逃出
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
typedef struct point
{
	int x,y,t;
	friend bool operator<(point a,point b)
	{
		return a.t>b.t; //结构体中，x小的优先级高
	}
}point;
priority_queue<point> p;
void bfs();
int check(int x,int y);
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF)
	{
		getchar();
		int i,j;
		for(i = 0;i<N;i++)
		{
			for(j = 0;j<M;j++)
			{
				scanf("%d",&map[i][j]);
			}
			getchar();
		}
		escape = 0;
		memset(visit,0,sizeof(visit));
		while(p.size!=0)       //清空优先队列
		{
			p.pop;
		}
		point start;           //将起点放入优先队列
		start.x = 0;
		start.y = 0;
		start.t = 0;
		p.push(start);
		bfs();
		if(escape)
		{
			for(i = 0;i<N;i++)
			{
				for(j = 0;j<M;j++)
				{
					printf("%d ",way[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("God please help our poor hero.\n");
			printf("FINISH\n");
		}
	}
}
void bfs()
{
	while(p.size!=0)
	{
		point now = p.top;
		p.pop;
		for(int i = 0;i<4;i++)
		{
			int change_x = now.x+dir[i][0];
			int change_y = now.y+dir[i][1];
			if(check(change_x,change_y))
			{

				way[change_y][change_x] = i;               //方向
				point next;
				int add;
				if(map[change_y][change_x]>='1' && map[change_y][change_x]<='9')
				{
					add = map[change_y][change_x] - '0'+1;
				}
				else
				{
					add = 1;
				}
				next.t = now.t+add;
				next.x = change_x;
				next.y = change_y;
				p.push(next);
				if(change_x == N-1 && change_y == M-1)
				{
					escape = 1;
					return;
				}
			}
		}
	}
}
int check(int x,int y)
{
	if(change_x<0 || change_y<0 || change_x>M-1 || change_y>N-1 || map[change_y][change_x] == 'X' || visit[change_y][change_x] == 1)
	{
		return 0;
	}
	return 1;
}
