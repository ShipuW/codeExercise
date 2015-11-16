#include<iostream>

int T;
int A,B;
int i;
__int64 j;

int main()
{
	scanf("%d",&T);
	for(i = 1;i<=T;i++)
	{
		scanf("%d%d",&A,&B);
		__int64 sum = 0;
		for(j = A;j<=B;j++)
		{
			sum += j*j*j;
		}
		printf("Case #%d: %I64d\n",i,sum);
	}
	return 1;
}