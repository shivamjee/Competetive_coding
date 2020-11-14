#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef long long int ll;

bool checkIfExist(vector<int>& arr) {
    //make a hashtable
    //int has[1001][2], i,m,n;
    int i,m,n;
    vector<vector<int> > has(1001,vector<int>(2,0));
    //store elem in hashtable
    for(i=0; i<arr.size(); i++)
    {
        if(arr[i]>0)
            has[arr[i]][0]= 1;
        else if(arr[i]==0)
        {
        	has[arr[i]][0]+= 1;
        	if(has[0][0]>1)
                return true;

        }
        else
            has[abs(arr[i])][1]=1;  // negative num stored in col 2
    }
    
    //search from arr in hashtable
    for(i=0; i<arr.size();i++)
    {
    	
        if(arr[i]%2 ==0)
        {
            m= arr[i]/2;
           if(arr[i]>0 && has[m][0]==1)
           {
       			cout<<arr[i]<<m<<endl;
               return true;
           }
           if(arr[i]<0 && has[abs(m)][1]==1)
               return true;
        }
        
    }
    return false; 
}	
int main()
{
	vector<int> arr;
	arr.push_back(4);
	arr.push_back(-7);
	arr.push_back(11);
	arr.push_back(4);
	arr.push_back(18);
	cout<<checkIfExist(arr)<<endl;
}








