#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue <int> que_big;
priority_queue <int,vector<int>,greater<int> > que_less;
int main()
{
	while(cin>>n)
	{
		if(n == 0)
		{
			break;
		}
		while(!que_big.empty())
		{
			que_big.pop();
		}
		while(!que_less.empty())
		{
			que_less.pop();
		}
		long long count = 0;
		int i,j;
		int k;
		for(i = 0;i<n;i++)
		{
			cin>>k;
			int temp;
			for(j = 0;j<k;j++)
			{
				cin>>temp;
				que_big.push(temp);
				que_less.push(temp);
			}
			count += (que_big.top()-que_less.top());
			que_big.pop();
			que_less.pop();
		}
		cout<<count<<"\n";
	}
	return 0;
}
