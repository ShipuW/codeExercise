#include<stdio.h>
#include<stdlib.h>
int T,N,M,K;
int i;
typedef struct point
{
	int position;
	int value;
}p;

p pp[100010];

int cmp(const void *a, const void *b);

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&N,&M,&K);
		for(i = 0;i<N;i++)
		{
			scanf("%d%d",&pp[i].position,&pp[i].value);
		}
		qsort(pp,N,sizeof(p),cmp);
		while(M--)
		{
			int temp;
			scanf("%d",&temp);

		}
	}
	return 1;
}

int cmp(const void *a, const void *b)  
{
    return (*(p *)a).value - (*(p *)b).value;  
}  