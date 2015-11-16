#include<stdio.h>
int arr[10][10];       //maze matrix
typedef struct point
{
	int x;
	int y;
	int front;    //former subscript
}point;
point p[100];
int i,j;
int start;    //begin subscript in queue
int end;      //end subscript in queue
int bfs();
int main()
{
	int i,j;
	for(i = 0;i<5;i++)
	{
		for(j = 0;j<5;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	p[0].x = 0;         //beginning
	p[0].y = 0;
	start = 0;          //begin location
	end = 0;            //end location
	arr[0][0] = 2;      //visited
	int end_index = bfs();
	int max_index = 0; 
	point path[100];
	while(end_index!=0)
	{
		path[max_index].x = p[end_index].x;
		path[max_index].y = p[end_index].y;
		max_index++;
		end_index = p[end_index].front;
	}
	max_index--;
	printf("(0, 0)\n");
	for(i = max_index;i>=0;i--)
	{
		printf("(%d, %d)\n",path[i].x,path[i].y);
	}
	return 0;
}
int bfs()
{
	int new_end = end;
	for(i = start;i<=end;i++)
	{
		int p_x = p[i].x;
		int p_y = p[i].y;
		if(p_y+1<=4 && arr[p_x][p_y+1] == 0)
		{
			arr[p_x][p_y+1] = 2;           //mark visited
			new_end++;
			p[new_end].x = p_x;
			p[new_end].y = p_y+1;
			p[new_end].front = i;
			if(p[new_end].x == 4 && p[new_end].y == 4) return new_end;
		}
		if(p_x+1<=4 && arr[p_x+1][p_y] == 0)
		{
			arr[p_x+1][p_y] = 2;           //mark visited
			new_end++;
			p[new_end].x = p_x+1;
			p[new_end].y = p_y;
			p[new_end].front = i;
			if(p[new_end].x == 4 && p[new_end].y == 4) return new_end;
		}
		if(p_x-1>=0 && arr[p_x-1][p_y] == 0)
		{
			arr[p_x-1][p_y] = 2;           //mark visited
			new_end++;
			p[new_end].x = p_x-1;
			p[new_end].y = p_y;
			p[new_end].front = i;
			if(p[new_end].x == 4 && p[new_end].y == 4) return new_end;
		}
		if(p_y-1>=0 && arr[p_x][p_y-1] == 0)
		{
			arr[p_x][p_y-1] = 2;           //mark visited
			new_end++;
			p[new_end].x = p_x;
			p[new_end].y = p_y-1;
			p[new_end].front = i;
			if(p[new_end].x == 4 && p[new_end].y == 4) return new_end;
		}
		start = end+1;
		end = new_end;
	}
}