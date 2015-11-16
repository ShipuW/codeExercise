/*failed*/

#include<stdio.h>

int n,a,b;
int need_area;
int real_area;

void find();
int main()
{
	while(scanf("%d%d%d",&n,&a,&b)!=EOF)
	{
		need_area = n*6;
		real_area = a*b;
		if(real_area>=need_area)
		{
			printf("%d\n",real_area);
			printf("%d %d\n",a,b);
		}
		else
		{
			int cha = need_area - real_area;
			int add_area = 0;
			int add_a = 0;
			int add_b = 0;
			for(;;add++)
			{
				int mark = 0;
				if(add%a == 0)
				{
					mark = 1;
					add_a++;
				}
				if(add%b == 0)
				{
					mark = 1;
					add_b++;
				}
				if(add>=cha && mark == 1)
				{
					break;
				}
			}
			printf("%d\n",real_area+add);
			printf("%d %d\n",a,b);
		}
	}
	return 0;
}
