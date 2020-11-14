#include <iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;
	int i;
	for(i=0;i<str.length()-k+1;i++)
	{
		if(str[i] == str[i+k-1])
		{
			//char arr[k+1] = {[ 0 ... k-1] = str[i]};
			char arr[k+1];
			fill_n(arr, k, str[i]);
			arr[k] = '\0';
			//cout<<str.substr(i,k)<<endl;
			if(str.substr(i,k).compare(arr) == 0)
			{

				str.erase(i,k);
				//cout<<"k"<<endl;
				i = -1;
				if(str.length()==1)
					break;
			} 
		}
		
	}
	cout<<str<<endl;
	return 0;
}
/*

int main() {
    string str1= "feeks";
    string str2= "ekegs";
    int p;
    for(int i=0; i<str2.length(); i++)
    {
        p= str1.find(str2[i]);
        if( p == -1)
        	break;
    	str1.erase(p,1);
    }
    if(str1.empty())
       cout<<"yes";
    else
       cout<<"no";
    return 0;
}*/


/*int main()
{
	string str;
	cin>>str;
	int k;
	cin>>k;
	for(int i=0;i<str.length()-k;i++)
	{
		int flag =0;
		if(str[i] == str[i+k-1])
		{
			for(int j =1;j<k;j++)
			{
				if(str[i+j]!=str[i])
				{
					flag=1;
					break;
				}
			}
			if(flag ==0)
			{
				str.erase(i,k);
				i=-1;
			}	
		}
		
	}
	cout<<str<<endl;
	return 0;
}*/

