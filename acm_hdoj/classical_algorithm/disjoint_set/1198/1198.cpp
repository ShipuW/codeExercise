#include<stdio.h>

typedef struct squares
{
	int left;
	int up;
	int right;
	int down;
}squares;

squares s[15];

int M,N;
int map[60][60];
int arr[3000];
//int rank[3000]; 

void bingchaji();
void init();
void merge(int x,int y);
int find(int x);
void init_s();

int main()
{
	init_s();
	while(scanf("%d%d",&M,&N)!=EOF)
	{
		init();           //init array
		if(M == -1 && N == -1)
		{
			break;
		}
		int i,j;
		getchar();
		for(i = 1;i<=M;i++)
		{
			for(j = 1;j<=N;j++)
			{
				scanf("%c",&map[i][j]);
			}
			getchar();
		}
		bingchaji();
		int count = 0;
		for(i = 1;i<=M*N;i++)
		{
			if(arr[i] == i)
			{
				count++;
			}
		}
		/*
		for(i = 1;i<=M*N;i++)
		{
			printf(" %d",arr[i]);
		}
		*/
		printf("%d\n",count);
	}
	return 1;
}
void bingchaji()
{
	int i,j;
	for(i = 1;i<=M;i++)
	{
		for(j = 1;j<=N;j++)
		{
			if(i>1 && s[(map[i][j]-'A'+1)].up == 1)     //try up   
			{
				if(s[(map[i-1][j]-'A'+1)].down == 1)
				{
					merge((i-1)*N+j,(i-2)*N+j);
				}
			}
			if(j>1 && s[(map[i][j]-'A'+1)].left == 1)     //try left
			{
				if(s[(map[i][j-1]-'A'+1)].right == 1)
				{
					merge((i-1)*N+j,(i-1)*N+j-1);
				}
			}
			if(j<N && s[(map[i][j]-'A'+1)].right == 1)     //try right
			{
				if(s[(map[i][j+1]-'A'+1)].left == 1)
				{
					merge((i-1)*N+j,(i-1)*N+j+1);
				}
			}
			if(i<M && s[(map[i][j]-'A'+1)].down == 1)     //try down
			{
				if(s[(map[i+1][j]-'A'+1)].up == 1)
				{
					merge((i-1)*N+j,(i)*N+j);
				}
			}
		}
	}
}
void init()
{
	int i;
	for(i = 1;i<=M*N;i++)
	{
		arr[i] = i;
//		rank[i] = 0;
	}
}
void merge(int x,int y)
{
	int ux = find(x);   //x set
	int uy = find(y);   //y set
	if(ux == uy)
	{
		return;
	}
	if(ux<uy)
	{
		arr[uy] = ux;
//		rank[ux]++;
	}
	else
	{
		arr[ux] = uy;
//		rank[uy]++;
	}
}
int find(int x)
{
	if(arr[x] != x)
	{
		arr[x] = find(arr[x]);
	}
	return arr[x];
}
void init_s()
{
	s[1].left = 1; s[1].up = 1;
	s[2].right = 1; s[2].up = 1;
	s[3].left = 1; s[3].down = 1;
	s[4].down = 1; s[4].right = 1;
	s[5].up = 1; s[5].down = 1;
	s[6].left = 1; s[6].right = 1;
	s[7].left = 1; s[7].right = 1; s[7].up = 1;
	s[8].left = 1; s[8].up = 1; s[8].down = 1;
	s[9].left = 1; s[9].right = 1; s[9].down = 1;
	s[10].right = 1; s[10].up = 1; s[10].down = 1;
	s[11].left = 1; s[11].up = 1; s[11].down = 1; s[11].right = 1;	
}
