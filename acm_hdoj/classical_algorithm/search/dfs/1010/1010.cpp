/*
1,//parity pruning
2,int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; // simplify code
3,if(N*M-wall<=T)        //pruning
{
    printf("NO\n");
    continue;
}                      
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int N,M,T;
int start_x,start_y;          //begin
int end_x,end_y;              //end
int mark;                     //can find end
char map[10][10];
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int start_x,int start_y,int time);
int check();
int main()
{
	while(scanf("%d%d%d",&N,&M,&T)!=EOF)
	{
		mark = 0;
		int wall = 0;                //wall count
		if(N == 0 && M == 0 && T == 0)
		{
			break;
		}
		int i,j;
		getchar();
		for(i = 0;i<N;i++)
		{
			for(j = 0;j<M;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j] == 'S')
				{
					map[i][j] = 'X';
					start_x = j;
					start_y = i;
				}
				else if(map[i][j] == 'D')
				{
					end_x = j;
					end_y = i;
				}
				else if(map[i][j] == 'X')
				{
					wall++;
				}
			}
			getchar();
		}
        if(N*M-wall<=T)
        {
            printf("NO\n");
            continue;
        }
		if(check())            //special: D is surrounded by X
		{
			printf("NO\n");
			continue;
		}
//		printf("    %d   %d\n",end_x,end_y);
		dfs(start_x,start_y,0);
		if(mark == 1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 1;
}
void dfs(int start_x,int start_y,int time)
{
//	printf("%d   %d    %d\n",start_x,start_y,time);
	if(time>T)
	{
		return;
	}
	if(start_x == end_x && start_y == end_y && time == T)
	{
		mark = 1;
		return;
	}
	int temp=(T-time)-(fabs(float(start_x-end_x))+fabs(float(start_y-end_y)));        //parity pruning
    if(temp<0||temp%2) 
	{
		return;
	}
	for(int i = 0;i<4;i++)
	{
		if(mark == 1)
		{
			return;
		}
		int change_x = start_x+dir[i][0];
		int change_y = start_y+dir[i][1];
		if(change_x<0 || change_x>M-1 || change_y<0 || change_y>N-1)
		{
			continue;
		}
		if(map[change_y][change_x] != 'X')
		{
			map[change_y][change_x] = 'X';
			dfs(change_x,change_y,time+1);
			map[change_y][change_x] = '.';
		}
	}
}
int check()
{
	int mark_2 = 0;
	if((end_x+1>M-1||map[end_y][end_x+1]=='X') && (end_y+1>N-1||map[end_y+1][end_x]=='X') && (end_x-1<0||map[end_y][end_x-1]=='X') && (end_y-1<0||map[end_y-1][end_x]=='X'))
	{
		mark_2 = 1;
	}
	return mark_2;
}