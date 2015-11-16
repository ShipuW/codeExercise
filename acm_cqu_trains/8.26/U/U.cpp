#include<stdio.h>
#include<math.h>

int p;
int i,j;

int main()
{
	while(scanf("%d",&p)!=EOF)
	{
		int count = 0;
		for(i = 2;i<p;i++)
		{
			int mark = 0;
			for(j = 1;j<=p-2;j++)
			{
				if(((int)(pow(i,j))-1)%p == 0)
				{
					mark = 1;
					break;
				}
			}
			if(((int)(pow(i,p-1))-1)%p != 0)
			{
				mark = 1;
			}
			if(mark == 0)
			{
				count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}