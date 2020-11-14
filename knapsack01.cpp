#include<iostream>
#include<vector>

using namespace std;
typedef long long int ll;


#define FOR(i,a,b) for(ll i = a;i<b;i++)


struct item
{
	ll value,weight;

	item(ll value,ll weight) : value(value), weight(weight)
	{}
};

bool cmpFunc(item a,item b)
{
	return (a.value)>(b.value);
}
int main()
{
	ll n,mw;
	cin>>n>>mw;
	vector<item> vec(n,item(0,0));
	FOR(i,0,n)
	{
		ll v,w;
		cin>>v>>w;
		vec[i] = item(v,w);
	}
	sort(vec.begin(),vec.end(),cmpFunc);

	double sum =0;
	int remaining = mw;
	FOR(i,0,n)
	{
		if(remaining<=0)
		{	break;}
		if(remaining>=vec[i].weight)
		{
			sum+= vec[i].value;
			remaining -= vec[i].weight;
		}	
	}
	cout<<sum<<" "<<mw-remaining<<endl;
	return 0;

}