#include <iostream>
#define MAX 502
using namespace std;
int str[MAX][MAX];
bool visit[MAX];//mark array (has been added into tree)
int distan[MAX];//record min dist between current tree to other node
int n;
int prim()//prim algorithm
{
    int v,i,j,maxi=0;
    visit[0]=true;//add the first node to tree
    for(i=0;i<n;i++)//calculate distan[i]
        distan[i]=str[0][i];
    
    for(j=1;j<n;j++)
    {
        int mini=65550;
        for (i=0;i<n;i++)//find min side
        {
            if(visit[i]==false&&distan[i]<mini)//find node with min weight
            {
                mini=distan[i];
                v=i;
            }
        }
        //cout<<mini<<' ';
        visit[v]=true;//mark node v, add to tree
        if(maxi<mini)
            maxi=mini;
        for (i=0;i<n;i++)//update weight
        {
            if(visit[i]==false&&distan[i]>str[v][i])//distan[i] min weight between spanning tree and node i
            {
                distan[i]=str[v][i];
            }
        }
    }
    return maxi;
}

int main()
{
    int i,j,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            visit[i]=false;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&str[i][j]);
            cout<<prim()<<endl;
    }
    return 0;
}