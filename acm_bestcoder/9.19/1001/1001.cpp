#include<stdio.h>
int T;
int a,b,c;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c == a || c == b)
		{
			printf("Yes\n");
			continue;
		}
		int new_b = a+b;
		int new_a = b;
		while(new_b<c)
		{
			int temp = new_a;
			new_a = new_b;
			new_b = temp+new_b;
		}
		if(new_b == c)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}