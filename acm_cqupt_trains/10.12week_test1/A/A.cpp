#include<stdio.h>
int M,N;
int main()
{
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		printf("%d\n",(M-1)+M*(N-1));
	}
	return 0;
}