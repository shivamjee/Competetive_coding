// #include <iostream>
//#include <bits/stdc++.h>
using namespace std;
#include<vector>
typedef long long int ll;

ll getSum(vector<ll> vec,ll n)
{
	ll mySum =vec[0];
	for(ll i = 1;i<n;i++)
		mySum+= llabs(vec[i]-vec[i-1]);
	//cout<<mySum<<endl;
	return mySum;
}
ll gcd(ll a,ll b)
{
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a == b)
		return a;
	if(a>b)
		return gcd(a-b,b);
	else
		return gcd(a,b-a);
}
int main() {
	int t;
	ll n,count,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> vec(n);
		for(ll i=0;i<n;i++)
			cin>>vec[i];
		sort(vec.begin(),vec.end());
		sum =0;count=0;
		do{
			count++;
			sum+=getSum(vec,n);
		}while(next_permutation(vec.begin(),vec.end()));
		ll g = gcd(sum,count);
		cout<<sum/g<<" "<<count/g<<endl;
	}
	return 0;
}