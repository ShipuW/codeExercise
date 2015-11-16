#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node *ufs;
struct node
{
	int parent[100001];
};
int flag[100001]={0},a1[100001];
int rBian,rNode;
int find(int e,ufs U)
{
	while(U->parent[e]!=e)
	{
		e=U->parent[e];
	}
	return e;
}
int key;
void ufunion(int i,int j,ufs u)
{
	u->parent[j]=i;
}
int main()
{
	ufs u;
	u=(ufs)malloc(sizeof(node));
	int n,m,i,t,a,b;
	while(scanf("%d %d",&a,&b)!=EOF&&a!=-1||b!=-1)
	{
		memset(flag,0,sizeof(flag));//init problem!
		if(a==0&&b==0)//special data
			printf("Yes\n");
		else
		{
			key=1;
			rBian=rNode=0;//side point init 0
			for(i=1;i<=100001;i++)
			{
				u->parent[i]=i;
			}
			while(a!=0&&b!=0)
			{
				int t1=find(a,u),t2=find(b,u);	
				if(t1==t2)//loop
					key=0;
				if(t1!=t2&&key)
				{
					rBian++;
					if(t1!=t2)
					{
						ufunion(t1,t2,u);
					}
					flag[t1]=flag[t2]=1;
				}
				scanf("%d %d",&a,&b);
			}
			int ans=0,k=0;
			for(i=1;i<=100001;i++)
			{
				if(flag[i]==1)
					a1[k++]=i;
				
			}
			rNode=k;
			for(i=0;i<k;i++)
			{
				if(u->parent[a1[i]]==a1[i])//father node is self, use another table
					ans++;
			}
			//printf("集合有%d 边%d 点%d\n",ans,rBian,rNode);
			if(key==0)//loop
				printf("No\n");
			else if(key&&rBian+1==rNode&&ans==1)//side+1=point，link all
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}