#include<stdio.h>
#include<stdlib.h>

int N,Q;
int i,j;
int arr[100010];
int add_num;

typedef struct tree
{
	int left;
	int right;
	int cover;
	tree *leftnode;
	tree *rightnode;
}tree;

tree *build(int l,int r);
void add(int start,int end,tree *root);

int main()
{
	tree *root = build(1,100000);
	scanf("%d%d",&N,&Q);
	for(i = 1;i<=N;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i = 1;i<=Q;i++)
	{
		char str[10];
		char a[5],b[5],c[5],d[5];
		int start,end;
		int type;     //mark input type
getchar();
		while(gets(str))
		{
			if(str[0] == 'Q')
			{
				type = 0;
				sscanf(str,"%s%s%s",a,b,c);
			}
			else if(str[0] == 'C')
			{
				type = 1;
				sscanf(str,"%s%s%s%s",a,b,c,d);
			}

//			printf("           %c %c\n",b[0],c[0]);
			start = atoi(b);
			end = atoi(c);
//			printf("           %d %d\n",start,end);

			if(!type)       //Q type
			{
				long long sum = 0;
				for(i = start;i<=end;i++)
				{
					sum+=arr[i];
				}
				printf("%lld\n",sum);
			}
			else            //C type
			{
				add_num = atoi(d);
				add(start,end,root);           //insert template
			}
		}
	}
	return 0;
}

tree *build(int l,int r)
{
	tree *root = new tree;
	root->left = l;
	root->right = r;
	root->leftnode = NULL;
	root->rightnode = NULL;

	if(l == r)
	{
		return root;
	}

	int mid = (r+l)/2;
	root->leftnode = build(l,mid);
	root->rightnode = build(mid+1,r);
	return root;
}

void add(int start,int end,tree *root)
{
	if(start == root->left && end == root->right)
	{
		for(i = start;i<=end;i++)
		{
			arr[i] += add_num;
		}
	}
	else
	{
		int mid = (root->left+root->right)/2;
		if(start<=mid)
		{
			add(start,mid,root->leftnode);
		}
		if(end>=mid+1)
		{
			add(mid+1,end,root->rightnode);
		}
	}
}