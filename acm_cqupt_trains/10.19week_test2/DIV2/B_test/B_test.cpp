#include<iostream>
#include<queue>
using namespace std;
int n;
priority_queue <int> que_big;
priority_queue <int,vector<int>,greater<int> > que_less;
int main()
{
	for(int i = 0;i<=10;i++)
	{
		que_big.push(i);
	}
//	que_big.push(10);
	cout<<que_big.top()<<endl;
	que_big.pop();
	cout<<que_big.top()<<endl;
	return 0;
}
