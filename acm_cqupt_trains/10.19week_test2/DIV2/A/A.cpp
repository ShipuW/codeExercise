#include<iostream>
#include<list>
#include<string>
using namespace std;
string s;
list<char> l;
list<char>::iterator it = l.begin();
int main()
{
	while(cin>>s)
	{
		l.clear();
		for(int i = 0;i<s.length();i++)
		{
			if(s[i] == '[')
			{
				it = l.begin();
			}
			else if(s[i] == ']')
			{
				it = l.end();
			}
			else
			{
				l.insert(it,s[i]);
			}
		}
		for(it = l.begin();it!=l.end();it++)
		{
			cout<<*it;
		}
		cout<<"\n";
	}
	return 0;
}