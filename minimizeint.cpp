#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		string even="",odd="";
		for(int i=0;i<str.length();i++)
		{
			if(str[i]%2==0)
				even+=str[i];
			else
				odd+=str[i];
		}
		merge(even.begin(),even.end(),odd.begin(),odd.end(),str.begin());
		cout<<str<<endl;
	}
		
	return 0;
}
