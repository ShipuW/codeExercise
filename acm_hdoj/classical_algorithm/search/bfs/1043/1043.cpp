#include<stdio.h>
int map[10][10];
int main()
{
	while(getchar(map[0][0]))
	{
		int i,j;
		for(i = 0;i<3;i++)
		{
			for(j = 0;j<3;j++)
			{
				if(i == 0 && j == 0)
				{
					continue;
				}
				getchar(map[i][j]);
			}
		}
		getchar();
		for(i = 0;i<3;i++)
		{
			for(j = 0;j<3;j++)
			{
				putchar(map[i][j]);
			}
		}
	}
	return 1;
}
