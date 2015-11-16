#include<stdio.h>
#include<string.h>

char str[1010];
int count[30];
int i,j;

int main()
{
	while(gets(str))
	{
		if(str[0] == '\0')
		{
			printf("First\n");
			continue;
		}
		memset(count,0,sizeof(count));
		for(i = 0;str[i] != '\0';i++)
		{
			count[str[i]-96]++;
		}
		int count_odd = 0;
		for(i = 1;i<=26;i++)
		{
			if(count[i]%2 == 1)
			{
				count_odd++;
			}
		}
		if(count_odd == 0 || count_odd%2 == 1)
		{
			printf("First\n");
		}
		else
		{
			printf("Second\n");
		}
	}
	return 0;
}