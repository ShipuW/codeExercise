#include<stdio.h>
int map[110][110];
int N,M;
int time;
int escape;        //can escape
typedef struct way
{
	int x;
	int y;
}way;
way w[100];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int x,int y,int time);
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
				scnaf("%d",&map[i][j]);
			}
			getchar();
		}
		time = 0;
		escape = 0;
		dfs(0,0,0);
	}
}
void dfs(int x,int y,int time)
{
	if(escape)
	{
		return;
	}
	for(int i = 0;i<4;i++)
	{
		int change_x = x+dir[i][0];
		int chenge_y = y+dir[i][1];
		if(map[change_x][chenge_y]!=X)
		{
			if(map[change_x][chenge_y]>='1' && map[change_x][chenge_y]<='9')
			{
				dfs(change_x,chenge_y,time);
			}
			else
			{
				
			}
		}
	}
}