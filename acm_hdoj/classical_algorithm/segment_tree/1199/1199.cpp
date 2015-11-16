/*tel*/
#include<stdio.h>
#include<string.h>
typedef struct wall
{
	int left;
	int right;
	int cover;
	wall *leftnode;
	wall *rightnode;
}wall;
int T;
int a,b;
char c;
int w[100010];
wall* create(int l,int r);
void insert(int a,int b,wall *root);
int main()
{
	wall *root = create(0,100010);
	while(scanf("%d",&T)!=EOF)
	{
		memset(w,0,sizeof(w));
		while(T--)
		{
			scanf("%d %d %c",&a,&b,&c);
			getchar();
			if(a>b)
			{
				int temp = b;
				b = a;
				a = temp;
			}
			insert(a,b,root);
		}
		int index_left = 0;
		int index_right = 0;
		int temp_left = 0;
		int temp_right = 0;
		int max = 0;
		int temp_max = 0;
		int start = 0;
		int has = 0;
		/*
		for(int j = 0;j<=10;j++)
		{
			printf(" %d",w[j]);
		}
		printf("\n");
		*/
		for(int i = 0;i<=100010;i++)
		{
			if(w[i] == 1)
			{
				has = 1;
				temp_max++;
				if(start == 0)
				{
					start = 1;
					temp_left = i;				
				}
			}
			if(w[i] == 0 && start == 1)
			{
				start = 0;
				temp_right = i-1;
				if(temp_max>max)
				{
					max = temp_max;
					index_left = temp_left;
					index_right = temp_right;
				}
				temp_left = 0;
				temp_right = 0;
				temp_max = 0;
			}
		}
		if(has == 1)
		{
			printf("%d %d\n",index_left,index_right);
		}
		else
		{
			printf("Oh, my god\n");
		}
	}
	return 0;
}
wall* create(int l,int r)
{
	wall *root = new wall;
	root->left = l;
	root->right = r;
	root->cover = 0;
	root->leftnode = NULL;
	root->rightnode = NULL;
	if(l<r)
	{
		int mid = (r+l)/2;
		root->leftnode = create(l,mid);
		if(l+1 == r)
		{
			root->rightnode = create(mid+1,r);
		}
		else
		{
			root->rightnode = create(mid,r);	
		}
	}
	return root;
}
void insert(int a,int b,wall *root)
{
//	printf("%d %d\n",root->left,root->right);
	if(a == b)
	{
		if(c == 'b')
		{
			for(int i = a;i<=b;i++)
			{
				w[i] = 0;
			}
		}
		else
		{
			for(int i = a;i<=b;i++)
			{
				w[i] = 1;
			}
		}
		return;
	}
	if(a<=root->left && b>=root->right)
	{
		if(c == 'b')
		{
//			root->cover = 0;
			for(int i = a;i<=b;i++)
			{
				w[i] = 0;
			}
		}
		else
		{
//			root->cover = 1;
			for(int i = a;i<=b;i++)
			{
				w[i] = 1;
			}
		}
	}
	else
	{
		if(a<(root->left+root->right)/2)
		{
			insert(a,b,root->leftnode);
		}
		if(b>(root->left+root->right)/2)
		{
			insert(a,b,root->rightnode);
		}
	}
}