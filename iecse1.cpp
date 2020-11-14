#include <iostream>
//include <bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long int ll;

void dfs(vector<vector<ll> > &graph,ll n, ll start,vector<bool> &isVisited)
{
	isVisited[start] = true;
	//cout<<start+1<<endl;
	for(ll i =0;i<n;i++)
	{
		//cout<<graph[start][i]<<endl;
		if(!isVisited[i] && graph[start][i])
			dfs(graph,n,i,isVisited);
	}
	return;
}
int main() {
	ll n,m,pi,qi;
	cin>>n>>m;
	vector<ll> arr(n);
	for(ll i =0;i<n;i++)
		cin>>arr[i];
	vector<vector<ll> > graph(n,vector<ll>(n,0));
	for(ll i =0;i<m;i++)
	{
		cin>>pi>>qi;
		graph[pi-1][qi-1] = 1;
		graph[qi-1][pi-1] = 1;
	}

	vector<bool> isVisited(n,false);
	vector<bool> check(n,true);
	ll cost = 0;
	while(isVisited != check)
	{
		cost+= *min_element(arr.begin(),arr.end());
		ll index = min_element(arr.begin(),arr.end())-arr.begin();
		arr[index] = 1000000001;
		dfs(graph,n,index,isVisited);
		//cout<<endl;
	}
	cout<<cost<<endl;
	
	return 0;
}