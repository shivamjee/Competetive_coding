#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

void goLtoR(ll ti, ll bi,ll ei,ll x)
{
	if(ei>=bi)
		cout<<ti+(ei-bi)<<endl;
	else
		cout<<ti+((x-bi)*2)+(bi-ei)<<endl;
}
void goRtoL(ll ti, ll bi,ll ei,ll x)
{
	if(ei<=bi)
		cout<<ti+(bi-ei)<<endl;
	else
		cout<<ti+((bi-1)*2)+(ei-bi)<<endl;
}

int main() {
	ll n,x,bi,ei,ti,addTime;
	cin>>n>>x;
	ll check = (x-1)*2;
	for(int i = 0;i<n;i++)
	{
		cin>>bi>>ei>>ti;
		if(ei == bi)
			cout<<ti<<endl;
		
		ll temp = ti%check;
		if(temp>=x)
		{
			//cout<<"hi"<<endl;
			ll temp2 = temp-(2*(temp%x)+1);
			if(temp2>=bi)
				addTime = temp2-bi;
			else
				addTime = (temp2-1)*2+(bi-temp2);
			ti += addTime;

			//cout<<addTime<<endl;
			if(ti%check>=x)
				goRtoL(ti,bi,ei,x);
			else
				goLtoR(ti,bi,ei,x);
		}
		else
		{
			
			if(temp+1<=bi)
				addTime = bi-temp-1;
			else
				addTime = (x-bi)*2+(bi-temp-1);
			ti += addTime;

			//cout<<addTime<<endl;
			if(ti%check>=x)
				goRtoL(ti,bi,ei,x);
			else
				goLtoR(ti,bi,ei,x);
		}
	}
	return 0;
}
/*

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
	ll n,m,s;
	cin>>n>>m>>s;
	ll temp,count = 0,ans=0;
	for(int i =0;i<n;i++)
	{
		cin>>temp;
		if(temp<=m)
			count++;
		else
			count = 0;
		if(count>=s)
			ans++;	
	}
	cout<<ans<<endl;
	return 0;
}*/