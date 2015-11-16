#include<stdio.h>

char str[1010];

int main()
{
	while(gets(str))
	{
		if(str[0]>=97 && str[0]<=122)
		{
			str[0] -= 32;
		}
		puts(str);
	}
}