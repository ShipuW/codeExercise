#include<stdio.h>
#include<string.h>

int N;
int count;
char map[110][110];      //map
int auxi[110][110];      //mark visit on map
int dp[110][110];
int max_count;

int search(int i,int j,int turn);
typedef struct point
{
	int x;
	int y;
}p;

p last,now;
int check_if_turn(p last,p temp_now,p now);

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		if(N == 0)
		{
			break;
		}
		int i,j;
		getchar();
		for(i = 0;i<N;i++)
		{
			for(j = 0;j<N;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j] == '#')
				{
					auxi[i][j] = 2;             //wall
				}
				else if(map[i][j] == '.')
				{
					auxi[i][j] = 0;             //available way without visit
				}
			}
			getchar();
		}
		/*
		if(N == 1 && map[0][0] == '.')
		{
			printf("%d\n",1);
			continue;
		}
		else if(N == 1 && map[0][0] == '#')
		{
			printf("%d\n",0);
			continue;			
		}
		*/
		int max_2 = 0;
		memset(dp,0,sizeof(dp));
		for(i = 0;i<N;i++)
		{
			for(j = 0;j<N;j++)
			{
				count = 0;
				if(map[i][j] == '.')
				{
					max_count = 0;

					count = 1;
					int turn = 0;

					last.x = i;
					last.y = j;
					now.x = i;
					now.y = j;
					search(i,j,turn);
//					int result = search(i,j,turn);
					if(max_2<max_count)
					{
						max_2 = max_count;
					}
					printf("\n");
				}
			}
		}
		printf("%d\n",max_2);
		/*
		int max_2 = dp[0][0];
		for(i = 0;i<N;i++)
		{
			for(j = 0;j<N;j++)
			{
				printf("%d ",dp[i][j]);
				if(max_2<dp[i][j])
				{
					max_2 = dp[i][j];
				}
			}
			printf("\n");
		}
		*/
	}
	return 0;
}

int search(int i,int j,int turn)
{
	printf("%d     %d     %d %d\n",count,turn,i,j);
	/*
	if(dp[i][j])
	{
		return dp[i][j];
	}
	*/
	if(j<N-1 && auxi[i][j+1] == 0 && turn < 2)            //try right
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.x += 1;
			auxi[i][j+1] = 1;                 //mark visited
			count++;
			search(i,j+1,turn);
			count--;
			/*
			count++;
			int result = search(i+1,j,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i][j+1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x+1;
			next.y = now.y;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
				now.x++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i][j+1] = 1; 
			count++;
			search(i,j+1,turn);
			count--;
				/*
				count++;
			int result = search(i+1,j,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i][j+1] = 0;
			}
			else if(turn_2 == 1)
			{
				now.x++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i][j+1] = 1; 
			count++;
			search(i,j+1,turn+1);
			count--;
				/*
				count++;
			int result = search(i+1,j,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i][j+1] = 0;
			}
		}
	}
	if(i<N-1 && j<N-1 && auxi[i+1][j+1] == 0 && turn < 2)            //try right down
	{
		if(last.x == now.x && last.y == now.y)      //if beginning
		{
			now.x += 1;
			now.y += 1;
			auxi[i+1][j+1] = 1;                 //mark visited
			count++;
			search(i+1,j+1,turn);
			count--;
			/*
			count++;
			int result = search(i+1,j+1,turn);;
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i+1][j+1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x+1;
			next.y = now.y+1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
				now.x++;
				now.y++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j+1] = 1; 
			count++;
			search(i+1,j+1,turn);
			count--;
				/*
				count++;
			int result = search(i+1,j+1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j+1] = 0;
			}
			else if(turn_2 == 1)
			{
				now.x++;
				now.y++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j+1] = 1; 
			count++;
			search(i+1,j+1,turn+1);
			count--;
				/*
				count++;
			int result = search(i+1,j+1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j+1] = 0;
			}
		}
	}
	if(i<N-1 && auxi[i+1][j] == 0 && turn < 2)            //try down
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning 
		{
			now.y += 1;
			auxi[i+1][j] = 1;                 //mark visited
			count++;
			search(i+1,j,turn);
			count--;
			/*
			count++;
			int result = search(i,j+1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i+1][j] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x;
			next.y = now.y+1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
				now.y++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j] = 1; 
			count++;
			search(i+1,j,turn);
			count--;
				/*
				count++;
			int result = search(i,j+1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j] = 0;
			}
			else if(turn_2 == 1)
			{
				now.y++;
			printf("last.x:%d last.y:%d temp_now.x:%d temp_now.y:%d now.x:%d now.y:%d\n",last.x,last.y,temp_now.x,temp_now.y,now.x,now.y);
			printf("turn_2 :%d\n",turn_2);
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j] = 1; 
			count++;
			search(i+1,j,turn+1);
			count--;
				/*
				count++;
			int result = search(i,j+1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j] = 0;
			}
		}
	}
	if(j>0 && i<N-1 && auxi[i+1][j-1] == 0 && turn < 2)            //try left down
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.y += 1;
			now.x -= 1;
			auxi[i+1][j-1] = 1;                 //mark visited
			count++;
			search(i+1,j-1,turn);
			count--;
			/*
			count++;
			int result = search(i-1,j+1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i+1][j-1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.y = now.y+1;
			next.x = now.x-1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
			now.y++;
			now.x--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j-1] = 1;
			count++;
			search(i+1,j-1,turn);
			count--;
				/*
				count++;
			int result = search(i-1,j+1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j-1] = 0;
			}
			else if(turn_2 == 1)
			{
			now.y++;
			now.x--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i+1][j-1] = 1; 
			count++;
			search(i+1,j-1,turn+1);
			count--;
				/*
				count++;
			int result = search(i-1,j+1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i+1][j-1] = 0;
			}
		}
	}
	if(j>0 && auxi[i][j-1] == 0 && turn < 2)            //try left
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.x -= 1;
			auxi[i][j-1] = 1;                 //mark visited
			count++;
			search(i,j-1,turn);
			count--;
			/*
			count++;
			int result = search(i-1,j,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i][j-1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x-1;
			next.y = now.y;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
				now.x--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i][j-1] = 1; 
			count++;
			search(i,j-1,turn);
			count--;
				/*
				count++;
			int result = search(i-1,j,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i][j-1] = 0;
			}
			else if(turn_2 == 1)
			{
				now.x--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i][j-1] = 1; 
			count++;
			search(i,j-1,turn+1);
			count--;
				/*
				count++;
			int result = search(i-1,j,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i][j-1] = 0;
			}
		}
	}
	if(i>0 && j>0 && auxi[i-1][j-1] == 0 && turn < 2)            //try left up
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.x -= 1;
			now.y -= 1;
			auxi[i-1][j-1] = 1;                 //mark visited
			count++;
			search(i-1,j-1,turn);
			count--;
			/*
			count++;
			int result = search(i-1,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i-1][j-1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x-1;
			next.y = now.y-1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
			now.x--;
			now.y--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j-1] = 1; 
			count++;
			search(i-1,j-1,turn);
			count--;
				/*
				count++;
			int result = search(i-1,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j-1] = 0;
			}
			else if(turn_2 == 1)
			{
			now.x--;
			now.y--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j-1] = 1; 
			count++;
			search(i-1,j-1,turn+1);
			count--;
				/*
				count++;
			int result = search(i-1,j-1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j-1] = 0;
			}
		}
	}
	if(i>0 && auxi[i-1][j] == 0 && turn < 2)            //try up
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.y -= 1;
			auxi[i-1][j] = 1;                 //mark visited
			count++;
			search(i-1,j,turn);
			count--;
			/*
			count++;
			int result = search(i,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i-1][j] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.x = now.x;
			next.y = now.y-1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
			now.y--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j] = 1;
			count++;
			search(i-1,j,turn);
			count--;				
				/*
				count++;
			int result = search(i,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j] = 0;
			}
			else if(turn_2 == 1)
			{
			now.y--;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j] = 1; 
			count++;
			search(i-1,j,turn+1);
			count--;
				/*
				count++;
			int result = search(i,j-1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j] = 0;
			}
		}
	}
	if(j<N-1 && i>0 && auxi[i-1][j+1] == 0 && turn < 2)            //try right up
	{
		if(last.x == now.x && last.y == now.y)      //if is beginning
		{
			now.y -= 1;
			now.x += 1;
			auxi[i-1][j+1] = 1;                 //mark visited
			count++;
			search(i-1,j+1,turn);
			count--;
			/*
			count++;
			int result = search(i+1,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
			count--;
			*/
			auxi[i-1][j+1] = 0;
		}
		else
		{
			p temp_now,next;
			temp_now.x = now.x;
			temp_now.y = now.y;
			next.y = now.y-1;
			next.x = now.x+1;
			int turn_2 = check_if_turn(last,temp_now,next);
			if(turn_2 == 0)
			{
			now.y--;
			now.x++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j+1] = 1; 
			count++;
			search(i-1,j+1,turn);
			count--;
				/*
				count++;
			int result = search(i+1,j-1,turn);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j+1] = 0;
			}
			else if(turn_2 == 1)
			{
			now.y--;
			now.x++;
				last.x = temp_now.x;
				last.y = temp_now.y;
				auxi[i-1][j+1] = 1; 
			count++;
			search(i-1,j+1,turn+1);
			count--;
				/*
				count++;
			int result = search(i+1,j-1,turn+1);
			dp[i][j] = dp[i][j]>result?dp[i][j]:result;
			dp[i][j] += 1;
				count--;
				*/
				auxi[i-1][j+1] = 0;
			}
		}
	}
	if(max_count<count && turn<2)
	{
		max_count = count;
	}
//	printf("%d    ",count);

	return count;
	/*
	if(dp[i][j] == 0)
	{
		dp[i][j] = 1;
	}
	return dp[i][j];
	*/
}

int check_if_turn(p last,p temp_now,p now)
{
	int first_x = temp_now.x - last.x;     //x-component of vector 1 
	int first_y = temp_now.y - last.y;     //y-component of vector 1
	int second_x = now.x - temp_now.x;     //x-component of vector 2
	int second_y = now.y - temp_now.y;     //y-component of vector 2
 	if((first_x*second_x + first_y*second_y) == 0)      //a 90 turn point
	{
		return 1;
	}
	if((double)(first_y)/(double)(first_x) == (double)(second_y)/(double)(second_x))  //Æ½ÐÐ
	{
		return 0;
	}
	else                                               //not a 90 turn point
	{
		return 2;
	}
}