#include<stdio.h>

int m,n;
int Recursive(int step);
int count_1;
int count_2;

int main()
{
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		int step = 0;
		count_1 = 0;
		count_2 = 0;
		Recursive(step);
		printf("%.5lf",(double)(count_1)/(double)(count_2));
	}
	return 0;
}

int Recursive(int step)
{
	int i;
	if(step == n)
	{
		count_1++;
		count_2++;
		return 1;
	}
	if(step>n)
	{
		count_2++;
		return 1;
	}
	for(i = 1;i<=m;i++)
	{
		Recursive(step+i);
	}
}