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
		int arr[26]={0};
		if(str.length()==1)
		{
			cout<<str<<endl;
		}
		else
		{
			for(char ch='a';ch<='z';ch++)
			{
				vector<int>pos;
				for(int i=0;i<str.length();i++)
				{
					if(str[i]==ch)
					{
						pos.push_back(i);
					}
				}
				if(pos.size()&1)
				{
					arr[ch-'a']=1;
				}
				else
				{
					bool flag=false;
					for(int i=1;i<pos.size();i++)
					{
                          if(pos[i]-pos[i-1]==1)
                          {
                          	i++;
                          }
                          else
                          {
                          	flag=true;
                          	break;
                          }
					}
					if(flag)
					{
						arr[ch-'a']=1;
					}
				}

			}
			string ans="";
			for(int i=0;i<26;i++)
			{
				if(arr[i])
				{
					ans+=(char)(97+i);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
