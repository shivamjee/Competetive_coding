#include<iostream>
#include<string>

using namespace std;


int main()
{
	string str;
	cin>>str;
	int max = 0;
	int flag = 0;
	if(str[0] == '-')
	{
		flag = 1;
		str.erase(0,1);
	}
	for(int i=0;i<str.size();i++)
	{
		string temp = str;
		temp.insert(i,"5");
		if(stoi(temp)>-8000 && stoi(temp) <8000)
			if(stoi(temp)>max)
				max = stoi(temp);

	}
	if(flag == 1)
		cout<<"-"<<max<<endl;
	else
		cout<<max<<endl;
	return 0;
}