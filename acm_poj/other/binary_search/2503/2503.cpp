/*
1,gets() sscanf() usage
2,binary search
3,quick sort
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dictionary
{
	char words[20];
	char orig[20];
}dictionary;
dictionary dic[100010];
int index = 0;

int compare(const void* a,const void* b);
//int binary_search(int front,int current,int end,char str[]);
int binary_search(char str[]);

int main()
{
//	int i,j;
	char str[25];
	while(gets(str))
	{
		if(str[0] == '\0')
		{
			break;
		}
		sscanf(str,"%s%s",dic[index].words,dic[index].orig);
		index++;
	}
	qsort(dic,index,sizeof(dictionary),compare);
	while(gets(str))
	{
		//int current = index/2;
		//int find_index = binary_search(0,current,index,str);
		int find_index = binary_search(str);
		if(find_index == -1)
		{
			printf("eh\n");
		}
		else
		{
			printf("%s\n",dic[find_index].words);
		}
	}
	return 0;
}

int binary_search(char str[])
{
	int front = 0,end = index,current;
	while(front<=end)
	{
		current = (front+end)/2;
		if(strcmp(dic[current].orig,str) == 0)
		{
			return current;
		}
		else if(strcmp(dic[current].orig,str) > 0)
		{
			end = current-1;
		}
		else
		{
			front = current+1;
		}
	}
	return -1;
}

int compare(const void* a,const void* b)
{
	return strcmp((*(dictionary*)a).orig,(*(dictionary*)b).orig);
}

/*
int binary_search(int front,int current,int end,char str[])
{
	if(current>end || current<front)
	{
		return -1;
	}
	if(strcmp(dic[current].orig,str) == 0)
	{
		return current;
	}
	else if(strcmp(dic[current].orig,str) > 0)
	{
		binary_search(front,(front+current)/2,current,str);
	}
	else
	{
		binary_search(current,(current+end)/2,end,str);
	}
}
*/
