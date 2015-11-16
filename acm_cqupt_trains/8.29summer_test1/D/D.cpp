/*failed*/

#include<stdio.h>
#include<string.h>

//int node[60000];     //node array
int weig[60000];     //node weight
int bran[60000];     //node branch
int N,K;
int i,j;

int main()
{
	while(scanf("%d%d",&N,&K)!=EOF)
	{
		memset(weig,0,sizeof(weig));
		memset(bran,0,sizeof(bran));
		if(N == 0)
		{
			break;
		}
		int num_node = 1;       //node count init=1
		__int64 weight_num = 0;
		__int64 max_wei = 1234567890;
		int year = 2;           //year init=1
		while(year<=N)
		{
			printf("%d\n",num_node);
			if(weight_num>max_wei)
			{
				break;
			}
			int now_node = num_node;     //current node count
			for(i = 1;i<=now_node;i++)
			{
				if(bran[i]<K)
				{
					num_node++;
					bran[i]++;
				}
				if(weig[i] == 0 && weight_num>max_wei)
				{
					break;
				}
				weig[i]++;
				weight_num++;
			}
			year++;
		}
		printf("%I64d\n",weight_num);
	}
	return 0;
}