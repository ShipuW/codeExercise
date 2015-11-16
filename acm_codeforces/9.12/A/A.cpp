/*careful*/
#include<stdio.h>
int n,m,a,b;
int main()
{
	while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF)
	{
		if((double)(b)/(double)(m) < (double)(a))
		{
			int times = n/m;
			int rest = n%m;
			int result = times*b+rest*a;
			int result2 = (times+1)*b;
			printf("%d\n",result<result2 ? result:result2);
		}
		else
		{
			printf("%d\n",a*n);
		}
	}
	return 0;
}