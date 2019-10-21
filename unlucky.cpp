#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	int i=0,j=0;
	bool less=true;
	bool greater=true;
	string t1=str.substr(0,n);
	string t2=str.substr(n);
	sort(t1.begin(),t1.end());
	sort(t2.begin(),t2.end());
	//cout<<t1<<" "<<t2<<endl;
	//reverse(t2.begin(),t2.end());
	while(i<str.length())
	{
		if(t1[i]<=t2[i])
		{
			
			less=false;
			break;
		}
		i++;
	}
      i=0;
      while(i<str.length())
      {
      	if(t1[i]>=t2[i])
      	{
      		greater=false;
      		break;
      	}
      }
	if(less||greater)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
