#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		//vector<string>arr;
		//vector<int>len;
		//vector<pair<int,pair<int,int> >>p;
		int cnt0=0,cnt1=0;
		int oddlen=0;
		for(int i=0;i<n;i++)
		{
			string str;
			cin>>str;
			if(str.length()&1)
			{
				oddlen++;
			}
			//arr.push_back(str);
			//len.push_back(str.length());
			//int tcnt0=0,tcnt1=0;
			for(int j=0;j<str.length();j++)
			{
				if(str[j]=='0')
					cnt0++;
				else
					cnt1++;
			}
			//cnt0+=tcnt0;
			//cnt1+=tcnt1;
			//p.push_back({str.length(),tcnt0,tcnt1});
		}
		if(oddlen%2==0)
		{
			if(cnt0%2==0||(oddlen>0&&cnt0%2==cnt1%2))
				cout<<n<<endl;
			else
				cout<<n-1<<endl;
		}
		else if(cnt0%2!=cnt1%2)
		{
			cout<<n<<endl;
		}
		else
			cout<<n-1<<endl;
		
	}
	return 0;

}
