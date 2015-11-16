#include<stdio.h>
#include<string.h>

char str1[1000];
char str2[1000];
int arr[1000][1000];
int len1;
int len2;
int i,j;

int max(int a,int b);

int main()
{
	char str[2001];
	while(gets(str))
	{
		memset(arr,0,sizeof(arr));
		sscanf(str,"%s%s",str1,str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(i = 1;i<=len1;i++)
		{
			for(j = 1;j<=len2;j++)
			{
				if(str1[i-1] == str2[j-1])
				{
					arr[i][j] = arr[i-1][j-1]+1;
				}
				else
				{
					arr[i][j] = max(arr[i-1][j],arr[i][j-1]);
				}
			}
		}
		printf("%d\n",arr[len1][len2]);
	}
	
	return 0;
}

int max(int a,int b)
{
	return a>b?a:b;
}