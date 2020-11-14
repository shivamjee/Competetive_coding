#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--)
	{
		/*int n;
	    cin>>n;
	    vector<int> vec;
	    
	    cout<<"size is "<<vec.size()<<endl;
	    for(int i=0;i<vec.size();i++)
	        cout<<vec[i];
	    cout<<endl;
	    
	    for(int i=0;i<vec.size();i++)
	        cin>>vec[i];

	    //cout<<vec.size()<<endl;
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
	        cout<<vec[i];

	    cout<<endl;
        cout<<"size is "<<vec.size()<<endl;

        vec.erase(vec.begin());
        cout<<"size is "<<vec.size()<<endl;
        for(int i=0;i<vec.size();i++)
	        cout<<vec[i];
	    cout<<endl;*/
	    int n;
	    cin>>n;
	    vector<int> vec(n,-1);

	    cout<<"size is "<<vec.size()<<endl;
	    for(int i=0;i<vec.size();i++)
	        cout<<vec[i];
	    cout<<endl;

	    cout<<"unknown ele "<<vec[vec.size()]<<endl;
	    
	    for(int i=0;i<vec.size();i++)
	        vec.push_back(i);

	    //cout<<vec.size()<<endl;
		sort(vec.begin(),vec.end());
		for(int i=0;i<vec.size();i++)
	        cout<<vec[i];

	    cout<<endl;
        cout<<"size is "<<vec.size()<<endl;

        vec.erase(vec.begin());
        cout<<"size is "<<vec.size()<<endl;
        for(int i=0;i<vec.size();i++)
	        cout<<vec[i];
	    cout<<endl;



        /*while(n>1)
        {
            if(vec[0]>vec[n-1])
            	//cout<<endl;
                vec.erase(vec.begin());
            else
            	//cout<<endl;
                vec.pop_back();
            n--;
        }
        cout<<vec[0]<<endl;*/
        
	}
	return 0;
}

/*int main() {	
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> vec(n,0);
        for(int i=0;i<n;i++)
            cin>>vec[i];
        for(int i=0;i<n;i++)
        {
            int pos = i-1;
            while(pos>=0)
            {
            	//cout<<vec[pos]<<" "<<vec[i]<<endl;
                if(vec[pos]>vec[i])
                {
                    //<<"zHi"<<" ";
                    break;
                }
                pos--;
            }
            cout<<i-pos<<" ";
        }
        cout<<endl;
    }
    return 0;
}*/	
/*	
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int k,sum =0;
	    int d0,d1,nextDig;
	    cin>>k>>d0>>d1;
	    sum += d0+d1;
	    nextDig = sum%10;
	    k -= 2;
	    while(k--)
	    {
	        sum += nextDig;
	        nextDig = sum%10;
	    }
	    if(sum%3==0)
	        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	    
	}
	return 0;
}*/