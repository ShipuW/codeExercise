#include<stdio.h>
#include<math.h>
#include<string.h>

int T;
__int64 x,y,k;

__int64 gcd(__int64 x,__int64 y);

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&k);
		__int64 g = gcd(x,y);
		/*
		int *prime = new int[g+1];
		int *vis = new int[g+1];
		//filtrate prime
		int m = sqrt(g+0.5);
		int c = 0;
		for(int t = 0;t<=g;t++)
		{
			vis[t] = 0;
		}
		for(int i = 2;i<=m;i++)
		{
			if(!vis[i])
			{
				prime[c++] = i;
				for(int j = i*i;j<=g;j+=i)
				{
					vis[j] = 1;
				}
			}
		}
//		int index = 0;
//		int fin_2 = 0;
*/
		__int64 r = g;
		for(;r>=1;)
		{
			if(g%r == 0)
			{
				k--;
			}
			if(k == 0)
			{
				printf("%I64d\n",r);
				break;
			}
			if(r == g)
			{
				r = g/2;
			}
			else
			{
				r--;
			}
		}
		if(k>0)
		{
			printf("-1\n");
		}
		/*
		for(int r = 2;r<=k;r++)
		{
			int fin = 0;
			int mark = 1;
			while(mark)
			{
				if(index>c-1)
				{
					printf("-1\n");
					fin = 1;
					break;
				}
				if(g%prime[index] == 0)
				{
					g/=prime[index];
					mark = 0;
				}
				else
				{
					index++;
				}
			}
			if(fin == 1)
			{
				fin_2 = 1;
				break;
			}
		}
		if(fin_2 == 1)
		{
			continue;
		}
		printf("%d\n",g);
		*/
	}
	return 0;
}

__int64 gcd(__int64 x,__int64 y)
{
	return y == 0 ? x:gcd(y, x%y);
}