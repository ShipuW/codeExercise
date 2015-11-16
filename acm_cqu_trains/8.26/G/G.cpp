#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n;
int i;
char str[35][25];

char find_1();
char* find_2();

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		for(i = 0;i<n;i++)
		{
			gets(str[i]);
		}
		char result_1 = find_1();
		if(result_1 != '0')
		{
			printf("%c\n",result_1);
		}
		else
		{
			find_2();
		}
	}
	return 0;
}

char find_1()
{
	char c;
	char *position;
	for(c = 'a';c<='z';c++)
	{
		int mark = 0;                 //has appeared? Default no 
		for(i = 0;i<n;i++)
		{
			position = strchr(str[i],c);
			if(position != NULL)
			{
				mark = 1;           //appeared
				break;
			}
		}
		if(!mark)
		{
			return c;
		}
	}
	return '0';          //if all character have appeared, return '0'
}

char* find_2()
{
	char c[5] = "aa";
	//char *c =(char *)malloc(sizeof(char)*2);
	char *position;
	for(c[0] = 'a';c[0]<='z';c[0]++)
	{
		for(c[1] = 'a';c[1]<='z';c[1]++)
		{
			int mark = 0;                 
			for(i = 0;i<n;i++)
			{
				position = strstr(str[i],c);
				if(position != NULL)
				{
					mark = 1;           
					break;
				}
			}
			if(!mark)
			{
				printf("%s\n",c);
				return c;
			}
		}
	}
	return NULL;            //return
}