#include<stdio.h>
#include<string.h>

typedef struct number
{
	char str[110];    
	int index;    
}number;
number num[110];
int i = 1;           //number count
int j,k;

int result[110];    //result array
int result_index = 0;    //pointer

void add();
void print_result();

int main()
{
	while(gets(num[i].str))
	{
		if(strcmp(num[i].str,"0") == 0)
		{
			break;
		}
		num[i].index = strlen(num[i].str)-1;
		i++;
	}
	i--;
	add();
	print_result();
	return 0;
}
void add()
{
	int is_finished = 0;        //need end?
	int add = 0;            
	while(!is_finished)
	{
		is_finished = 1;
		int sum = 0;
		for(j = 1;j<=i;j++)
		{
			if(num[j].index>=0)
			{
				is_finished = 0;     //not end
				sum += num[j].str[num[j].index] - '0';
				num[j].index--;
			}
		}
		sum+=add;
		add = sum/10;
		if(!(sum == 0 && is_finished == 1))
		{
			result_index++;
			result[result_index] = sum%10;	
		}
		if(sum != 0 && is_finished == 1)
		{
			result[result_index] = sum;
		}
	}
}
void print_result()
{
	for(j = result_index;j>=1;j--)
	{
		printf("%d",result[j]);
	}
	printf("\n");
}