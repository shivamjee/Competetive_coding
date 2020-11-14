#include<iostream>
#include<string>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		//cout<<"enter string: ";
		cin>>str;
		int mainCount = 0;
		int evenCount = 0;
		int oddCount = 0;
		//cout<<str.size()<<endl;
		for(int i=0;i<str.size();i++)
		{
			//cout<<str[str.size()-1-i]<<" ";
			if(str[str.size()-1-i]=='1')
			{
				if(mainCount%2==0)
					evenCount ++;
				else
					oddCount ++;
			}
			mainCount++;

		}
		//cout<<evenCount<<oddCount<<endl;
		if((evenCount - oddCount)%3 == 0)
			cout<<1<<endl;
		else
			cout<<0<<endl;

	}
}