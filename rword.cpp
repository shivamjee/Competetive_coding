#include <iostream>
#include<string>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin.ignore();
	    std:: getline(cin, str);
	    int endi = str.find(" ",0) ;
	    while(endi!=string::npos)
	    {
	        //cout<<endi;
	        str.erase(endi,1);
	        //cout<<str<<endl;
	        int temp = endi;
	        endi = str.find(" ",temp);
	    }
	    cout<<str<<endl;
	}
	//code
	return 0;
}

// reverse a string without reversing its words
/*#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    vector<string> v;
	    int starti=0;
	    int endi = str.find(".",starti);
	    while(endi != string::npos)
	    {
	    	//cout<<endi<<" ";
	        string temp = str.substr(starti,endi-starti);
	        v.insert(v.begin(),temp);
	        starti = endi+1;
	        endi = str.find(".",starti);
	    }
	    string temp = str.substr(starti,str.length()-starti);
        v.insert(v.begin(),temp);
	    for(int i = 0;i<v.size()-1;i++)
	        cout<<v[i]<<".";
        cout<<v[v.size()-1]<<endl;
        
	}
	return 0;
}*/