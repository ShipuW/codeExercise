#include<stdio.h>
#include<stdlib.h>

int W,H;
int i,j;
int start_x,start_y;
char arr[30][30];        //matrix
int auxi[30][30];      //visited
int count;            //count

int dfs(int x,int y);
int check(int x,int y);

int main()
{
	while(scanf("%d%d",&W,&H)!=EOF)
	{
		getchar();
		if(W<=0 || H<=0)
		{
			break;
		}
		for(i = 0;i<H;i++)
		{
			for(j = 0;j<W;j++)
			{
				scanf("%c",&arr[i][j]);
				if(arr[i][j] == '@')
				{
					start_x = i;
					start_y = j;
					auxi[i][j] = 1;         //beginning visited
				}
				else if(arr[i][j] == '#')
				{
					auxi[i][j] = 1;        //wall is visited   
				}
				else
				{
					auxi[i][j] = 0;       // not visited
				}
			}
			getchar();
		}
		count = 1;
		dfs(start_x,start_y);
		printf("%d\n",count);
	}
	return 0;
}

int dfs(int x,int y)
{
//	printf("%d-->",count);
//	printf("%d %d\n",x,y);
	if(x == start_x && y == start_y && check(x,y))                   //end 
	{
		return count;
	}
	if(y+1<W && arr[x][y+1] == '.' && auxi[x][y+1] == 0)
	{
		auxi[x][y+1] = 1;
		count++;
		dfs(x,y+1);
	}
	if(x+1<H && arr[x+1][y] == '.' && auxi[x+1][y] == 0)
	{
		auxi[x+1][y] = 1;
		count++;
		dfs(x+1,y);
	}
	if(y-1>=0 && arr[x][y-1] == '.' && auxi[x][y-1] == 0)
	{
		auxi[x][y-1] = 1;
		count++;
		dfs(x,y-1);
	}
	if(x-1>=0 && arr[x-1][y] == '.' && auxi[x-1][y] == 0)           
	{
		auxi[x-1][y] = 1;
		count++;
		dfs(x-1,y);
	}
}

int check(int x,int y)
{
	if(y+1<W && auxi[x][y+1] == 0)
	{
		return 0;
	}
	if(x+1<H && auxi[x+1][y] == 0)
	{
		return 0;
	}
	if(y-1>=0 && auxi[x][y-1] == 0)
	{
		return 0;
	}
	if(x-1>=0 && auxi[x-1][y] == 0)
	{
		return 0;	
	} 
	return 1;
}