#include<stdio.h>
#include<string.h>

int n;
int i,j;
char str[10];

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		getchar();
		int X = 0;
		for(i = 0;i<n;i++)
		{
			gets(str);
			if(strcmp(str,"X++") == 0 || strcmp(str,"++X") == 0)
			{
				X++;
			}
			else
			{
				X--;
			}
		}
		printf("%d\n",X);
	}
	return 0;
}