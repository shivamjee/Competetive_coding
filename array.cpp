#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	vector<int> v1;
	vector<int> v2;
	int n,m;
	cin >> n;
	for(int i =0;i<n;i++)
	{
		int temp;
		cin >> temp;
		v1.push_back(temp);
	}
	/*cin >> m;
	for(int i =0;i<m;i++)
	{
		int temp;
		cin >> temp;
		v2.push_back(temp);
	}*/
	int k;
	cin>>k;
	sort(v1.begin(),v1.end());
	cout<<v1.at(k-1)<<endl;
	for(auto i =v1.begin();i!= v1.end();i++)
	{
		 cout << *i << " ";
	}
	cout<< endl;
	/*for(auto i =v2.begin();i!= v2.end();i++)
	{
		 cout << *i << " ";
	}
	cout<< endl;*/	
	return 0;
}