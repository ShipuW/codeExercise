#include<iostream>
using namespace std;
#define N 55
struct pipe
{
	int block;
	char flower;
}p[N][N];
void Init(int n,int m)
{
	int i,j;
	for(i=1;i<m+1;i++)
		for(j=1;j<n+1;j++)
			p[i][j].block=0;
}
int main()
{
	int n,m;
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==-1&&n==-1) break;
		int i,j;
		char ch;
		int number=0;
		Init(n,m);
		int time=0;
		for(i=1;i<m+1;i++)
			for(j=1;j<n+1;j++)
			{
				cin>>ch;
				time++;
				p[i][j].flower=ch;
				char temp1=p[i][j-1].flower;   //left
				char temp2=p[i-1][j].flower;   //up
				if(i==1&&j==1){number++;p[i][j].block=time;continue;}
				else if(i==1)
				{
					if(!(ch=='J'||ch=='E'||ch=='B'||ch=='D')&&!(temp1=='C'||temp1=='E'||temp1=='H'||temp1=='A'))
						p[i][j].block=p[i][j-1].block;  //current has left, last have right, merge
					else {number++;p[i][j].block=time;}
				}
				else if(j==1)
				{
					if(!(ch=='C'||ch=='F'||ch=='I'||ch=='D')&&!(temp2=='B'||temp2=='F'||temp2=='G'||temp2=='A'))
						p[i][j].block=p[i-1][j].block;
					else {number++;p[i][j].block=time;}
				}
				else
				{
					if(ch=='C'||ch=='F'||ch=='I')
					{
						if(!(temp1=='C'||temp1=='E'||temp1=='H'||temp1=='A'))
							p[i][j].block=p[i][j-1].block;
						else {number++;p[i][j].block=time;}
					}
					else if(ch=='J'||ch=='E'||ch=='B')
					{
						if(!(temp2=='B'||temp2=='F'||temp2=='G'||temp2=='A'))
							p[i][j].block=p[i-1][j].block;
						else {number++;p[i][j].block=time;}
					}
					else if(ch=='G'||ch=='H'||ch=='K'||ch=='A')
					{
						if(!(temp1=='C'||temp1=='E'||temp1=='H'||temp1=='A')&&!(temp2=='B'||temp2=='F'||temp2=='G'||temp2=='A'))
						{
							int part1=p[i][j-1].block;
							int part2=p[i-1][j].block;
							if(part1!=part2)
							{
								int k,t;
								for(k=1;k<i+1;k++)  //some problems
									for(t=1;t<n+1;t++)
										if(p[k][t].block==part1) //change all part1 to part2
											p[k][t].block=part2;
										number--;
							}
							p[i][j].block=part2;
						}
						else if(!(temp1=='C'||temp1=='E'||temp1=='H'||temp1=='A')&&(temp2=='B'||temp2=='F'||temp2=='G'||temp2=='A'))  //ср+╥гоб
							p[i][j].block=p[i][j-1].block;
						else if((temp1=='C'||temp1=='E'||temp1=='H'||temp1=='A')&&!(temp2=='B'||temp2=='F'||temp2=='G'||temp2=='A'))
							p[i][j].block=p[i-1][j].block;
						else{number++;p[i][j].block=time;}
					}
					else if(ch=='D')
					{number++;p[i][j].block=time;}
				}
				
			}
			cout<<number<<endl;
	}
	return 0;
}