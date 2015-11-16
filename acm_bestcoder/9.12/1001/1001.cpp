#include<stdio.h>

int T;
int a,b,c;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int count = 0;
		scanf("%d%d%d",&a,&b,&c);
		c -= a;
		while(c>0)
		{
			if(c%b == 0)
			{
				count++;
			}
			c -= a;
		}
		printf("%d\n",count);
	}
	return 1;
}