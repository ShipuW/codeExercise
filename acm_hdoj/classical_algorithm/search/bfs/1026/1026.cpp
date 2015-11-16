#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int map[110][110];           //origin map
int way[110][110];           //secondary map for direction
int visit[110][110];         //mark visited
int N,M;
int escape;        //whether escape
int time;          //time use
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
typedef struct point
{
	int x,y,t;
	friend bool operator<(point a,point b)
	{
		return a.t>b.t; //smaller x has a higher priority in structure
	}
}point;
priority_queue<point> p;
void bfs();
int check(int x,int y);
void printf_way();
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
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		escape = 0;
		memset(visit,0,sizeof(visit));
		while(!(p.empty()))       //clear queue
		{
			p.pop();
		}
		point start;           //put begin point into queue
		start.x = 0;
		start.y = 0;
		start.t = 0;
		if(map[0][0]>='1' && map[0][0]<='9')
		{
			start.t = map[0][0] - '0';
		}
		p.push(start);
		bfs();
		if(escape)
		{
			/*
			for(i = 0;i<N;i++)
			{
				for(j = 0;j<M;j++)
				{
					printf("%d ",way[i][j]);
				}
				printf("\n");
			}
			*/
			printf_way();
		}
		else
		{
			printf("God please help our poor hero.\n");
			printf("FINISH\n");
		}
	}
	return 1;
}
void bfs()
{
	while(!(p.empty()))
	{
		point now = p.top();
		p.pop();
		for(int i = 0;i<4;i++)
		{
			int change_x = now.x+dir[i][0];
			int change_y = now.y+dir[i][1];
			if(check(change_x,change_y))
			{
				way[change_y][change_x] = i;               //direction
				visit[change_y][change_x] = 1;
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
				if(change_x == M-1 && change_y == N-1)
				{
					time = next.t;
					escape = 1;
					return;
				}
			}
		}
	}
}
int check(int change_x,int change_y)
{
	if(change_x<0 || change_y<0 || change_x>M-1 || change_y>N-1 || map[change_y][change_x] == 'X' || visit[change_y][change_x] == 1)
	{
		return 0;
	}
	return 1;
}
void printf_way()
{
	printf("It takes %d seconds to reach the target position, let me show you the way.\n",time);
	point path[10010];
	int index = 0;
	int x = M-1;
	int y = N-1;
	while(!(x == 0 && y == 0))
	{
		point p;
		p.x = x;
		p.y = y;
		path[index++] = p;
		int k = way[y][x];
		x = x-dir[k][0];
		y = y-dir[k][1];
	}
	point p;
	p.x = 0;
	p.y = 0;
	path[index] = p;
	int t = 1;
	while(index>0)
	{
		if(map[path[index].y][path[index].x]>='1' && map[path[index].y][path[index].x]<='9')
		{
			int num = map[path[index].y][path[index].x] - '0';
			for(int i = 1;i<=num;i++)
			{
				printf("%ds:FIGHT AT (%d,%d)\n",t++,path[index].y,path[index].x);
			}
		}
		printf("%ds:(%d,%d)->(%d,%d)\n",t++,path[index].y,path[index].x,path[index-1].y,path[index-1].x);
		index--;
	}
	if(map[path[index].y][path[index].x]>='1' && map[path[index].y][path[index].x]<='9')
	{
		int num = map[path[index].y][path[index].x] - '0';
		for(int i = 1;i<=num;i++)
		{
			printf("%ds:FIGHT AT (%d,%d)\n",t++,path[index].y,path[index].x);
		}
	}
	printf("FINISH\n");
}