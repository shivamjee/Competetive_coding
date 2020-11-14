#include <iostream>
#include<vector>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) 
	    	cin>>arr[i];
	    vector<int> stk;
	    stk.push_back(arr[0]);
	    //cout<<stk.back()<<endl;
	    for(int i =1;i<n;i++)
	    {
	        /*if(stk.front()>=arr[i])
	            stk.push_back(arr[i]);*/
            //else
            //{
            	//cout<<"hi"<<endl;
                while(!stk.empty() && stk.back()<arr[i])
                {
                    cout<<arr[i]<<" ";
                    stk.pop_back();
                }
                stk.push_back(arr[i]);
            //}       
	    }
	    while(!stk.empty()) 
	    {
	        cout<<-1<<" ";
	        stk.pop_back();
	    }
	    cout<<endl;
	}
	return 0;
}