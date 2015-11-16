#include <iostream>
#include <memory.h>
using namespace std;
int len;
int f[100001];
class tnode
{public:
  int left;
  int right;
  int color;
  tnode *lnode,*rnode;
  void create(int l,int r);
  void insert(int l,int r,int c);
  void calculate();
};
tnode tree[200002];
tnode *root=&tree[0];
void tnode::create(int l,int r)
{


 left=l;
 right=r;
 if(r-l==0)
 {
 lnode=rnode=NULL;
 return;
 
 }
lnode=&tree[len++];
rnode=&tree[len++];
int mid=(l+r)>>1;
lnode->create(l,mid);
rnode->create(mid+1,r);
 
}
void tnode::insert(int l,int r,int c)
{
	if(color==c)return;	
 if(l==left&&r==right)
 {color=c;return;
 }
 
 if(color!=-2)
 {
  lnode->color=color;
  rnode->color=color;
  color=-2;
 
 }
 	int mid = (left + right) >> 1;
	if(r <= mid){ lnode->insert(l, r, c); return;}
	if(l > mid){ rnode->insert(l, r, c); return;}

	lnode->insert(l, mid, c);
	rnode->insert(mid+1, r, c);

}
void tnode::calculate()
{
  if(color==-1)return;
  if(color!=-2)
	  for(int i=left;i<=right;i++)
		  f[i]=color;
  if(color==-2)
  {
   lnode->calculate();
   rnode->calculate();
  }


}

int main()
{
int t;
while(cin>>t)
{
len=1;
root->create(0,100000);
root->color=-1;
memset(f,-1,sizeof(f));
int a,b;
char c;
while(t--)
{
 cin>>a>>b>>c;
 if(c=='w')
	 root->insert(a,b,1);
 else if(c=='b')
	 root->insert(a,b,-1);
}
root->calculate();
int p1,p2;
int flag=0;
int imax=-1;
int k1=0,k2=0;
for(int i=1;i<=100000;i++)
{ 
	if(flag==0&&f[i]==1)
	{p1=i;
	flag=1;
	}
	if(flag==1&&f[i]==-1)
	{
	p2=i;
	if(p2-p1>=imax)
	{
		imax=p2-p1;
		k1=p1;
		k2=p2;
	}
	flag=0;
	
	}

}
if(imax==-1)cout<<"Oh, my god"<<endl;
else
cout<<k1<<" "<<--k2<<endl;
}

return 0;
}