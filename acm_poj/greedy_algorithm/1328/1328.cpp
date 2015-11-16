#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
typedef struct island
{
	int x;        
	int y;        
	double left;    
	double right;   
}island;
island is[1010];

int compare(const void* a,const void *b);
//int compare(island a,island b);
int main()
{
	int n,d;
	int times = 0;
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		if(n == 0 && d == 0)
		{
			break;
		}
		int i;
		int is_impossible = 0;
		for(i = 0;i<n;i++)
		{
			scanf("%d%d",&is[i].x,&is[i].y);
			if(is[i].y>d)
			{
				is_impossible = 1;
			}
			is[i].left = is[i].x-sqrt((double)(d*d-is[i].y*is[i].y));
			is[i].right = is[i].x+sqrt((double)(d*d-is[i].y*is[i].y));
		}
		if(is_impossible == 1)
		{
			printf("Case %d: -1\n",++times);
			continue;
		}
		qsort(is,n,sizeof(is[0]),compare);
	//	sort(is,is+n,compare);
		double temp_left = is[0].left;
		double temp_right = is[0].right;
		int count = 1;
		for(i = 1;i<n;i++)
		{
			if(is[i].left<=temp_right)
			{
				if(is[i].right<temp_right)
				{
					temp_right = is[i].right;
				}
			}
			else
			{
				count++;
				temp_left = is[i].left;
				temp_right = is[i].right;
			}
		}
		printf("Case %d: %d\n",++times,count);
	}
	return 0;
}
/*
int compare(island a,island b)
{
	return a.left<b.left;
}
*/

int compare(const void *a,const void *b)
{
	double aa = (*(island*)a).left;
	double bb = (*(island*)b).left;
	return aa>bb?1:-1;
}

