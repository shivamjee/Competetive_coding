#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h> 

typedef long long int ll;

#define FOR(i,a,b) for(ll i = a;i<b;i++)

using namespace std;


void bfs(vector<vector<ll> > &graph,ll n, ll start,vector<bool> &isVisited)
{

	vector<ll> queue;


	queue.insert(queue.begin(),start);
	isVisited[start] = true;

	while(queue.empty() == false)
	{
		ll temp = queue.front();
		queue.erase(queue.begin());
		cout<<temp+1<<endl;
		FOR(i,0,n)
		{
			if(!isVisited[i] and graph[temp][i])
			{
				queue.push_back(i);
				isVisited[i] = true;
			}
		}
	}
	return;
}


void dfs(vector<vector<ll> > &graph,ll n, ll start,vector<bool> &isVisited)
{
	isVisited[start] = true;
	cout<<start+1<<endl;
	FOR(i,0,n)
	{
		if(!isVisited[i] and graph[start][i])
			dfs(graph,n,i,isVisited);
	}
	return;
}

int main()
{
	int vertices,edges;
	cin>>vertices>>edges;
	vector<vector<ll> > graph(vertices,vector<ll>(vertices,0));

	FOR(i,0,edges)
	{
		ll u,v;
		cin >>u>>v;
		graph[u-1][v-1] = 1;
		graph[v-1][u-1] = 1; 
	}

	vector<bool> isVisited(vertices,false);

	bfs(graph,vertices,0,isVisited);

	int flag;

	FOR(i,0,vertices)
	{
		if(isVisited[i] == false)
		{
			flag = 1;
			break;
		}

	}
	if(flag == 1)
		cout<<"false"<<endl;
	else
		cout<<"true"<<endl;


	return 0;
}