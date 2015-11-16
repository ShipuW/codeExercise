#include<stdio.h>
#include<string.h>

int house[100010];

int merge(int A,int B);
int find(int num);
int max;

int main()
{
	int A,B;
	memset(house,0,sizeof(house));
	int mark = 0;
	while(scanf("%d%d",&A,&B)!=EOF)
	{
		int temp_max = A>B?A:B;
		max = max>temp_max?max:temp_max;
		if(A == -1 && B == -1)
		{
			break;
		}
		if(A == 0 && B == 0)
		{

int i;
/*
for(i = 1;i<=10;i++)
{
	printf("%d ",i);
}
printf("\n");
for(i = 1;i<=10;i++)
{
	printf("%d ",house[i]);
}
printf("\n");
*/
			int only_one = 0;
			for(i = 1;i<=max;i++)
			{
				if(house[i] == i)
				{
					only_one++;
				}
			}
			memset(house,0,sizeof(house));
			if(mark == 0 && only_one<=1)
			{
				printf("Yes\n");
			}
			else
			{
				mark = 0;
				printf("No\n");
			}
			max = 0;
			continue;
		}
		if(merge(A,B))
		{
			mark = 1;
		}
	}
	return 0;
}
int merge(int A,int B)
{
	int A_root = find(A);
	int B_root = find(B);
	if(A_root == B_root)
	{
		return 1;
	}
	else
	{
		A_root>B_root ? house[A_root] = B_root : house[B_root] = A_root;
		return 0;
	}
}

int find(int num)
{
	int result = num;
	while(house[result]!=0 && house[result]!=result)
	{
		result = house[result];
	}
	house[result] = result;
	int result2 = num;
	int j;
	while(house[result2]!=0 && house[result]!=result)
	{
		j = house[result2];
		house[result2] = result;
		result2 = j;
	}
	return result;
}