#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int N;
int arr[110];      //origin array
int auxi[110];     //mark chosen
int result[110];      //number
int max[110];      //record max result
int has_find;     //mark find result
int can_end;      //test odd num

void dfs(int i);
int check();
void compare();
void print_result();
int cmp(const void *a,const void *b);
void deal();

int main()
{
	while(scanf("%d",&N)!=EOF)
	{
		memset(auxi,0,sizeof(auxi));
		memset(max,0,sizeof(max));
		int i;
		for(i = 0;i<N;i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,N,sizeof(arr[0]),cmp);
		can_end = 1;
		deal();
		if(can_end)
		{
			printf("%d\n",-1);
			continue;
		}
		has_find = 0;
		dfs(0);
		print_result();
	}
	return 1;
}
void dfs(int i)
{
	if(i == N)
	{
		if(check())              //result is OK?
		{
			compare();
			has_find = 1;
			return;
		}
		return;
	}
	int j;
	for(j = 0;j<N;j++)
	{
		if(has_find == 1)
		{
			break;
		}
		if(auxi[j] == 0)
		{
			auxi[j] = 1;
			result[i] = arr[j];
			dfs(i+1);
			auxi[j] = 0;
		}
	}
}
int check()
{
	if(result[0] == 0 || result[N-1]%2 == 0)
	{
		return 0;
	}
	return 1;
}
void compare()
{
	for(int i = 0;i<N;i++)
	{
		if(max[i]<result[i])
		{
			for(int j = 0;j<N;j++)
			{
				max[j] = result[j];
			}
			break;
		}
		else if(max[i]>result[i])
		{
			break;
		}
	}
}
void print_result()
{
	int mark = 0;
	for(int i = 0;i<N;i++)
	{
		if(max[i] != 0)
		{
			mark = 1;
		}
	}
	if(mark == 0)
	{
		printf("%d\n",-1);
	}
	else
	{
		for(int i = 0;i<N;i++)
		{
			printf("%d",max[i]);
		}
		printf("\n");
	}
}
int cmp(const void *a,const void *b)
{
	return *(int *)b - *(int *)a;
}
void deal()
{
	int index;
	int index_value;
	int i;
	for(i = N-1;i>=0;i--)
	{
		if(arr[i]%2 == 1)
		{
			can_end = 0;
			index = i;
			index_value = arr[i];
			break;
		}
	}
	if(can_end == 1)
	{
		return;
	}
	for(i = index+1;i<N;i++)
	{
		arr[i-1] = arr[i];
	}
	arr[i-1] = index_value;

	int count_num = 0;
	for(i = N-1;i>=0;i--)
	{
		if(arr[i] != 0)
		{
			count_num++;
		}
	}
	if(count_num <= 1 && N>=2)
	{
		can_end = 1;
	}
}