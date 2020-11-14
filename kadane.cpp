#include <iostream>
using namespace std; 

typedef long long int ll;
#define FOR(i,a,b) for(ll i = a;i<b;i++)

int main() {
    ll t,n,k,i;
    cin>>t;
    
    while(t--)
    {
        ll maxValue=0;
        cin>>n>>k;
        FOR(i,1,k+1)
        {
            if((n%i)>maxValue)
                maxValue = n%i;
        }
        cout<<maxValue<<endl;
    }
	return 0;
}



/*#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int max,end=0;
	    for(int i=0;i<n;i++)
	    {
	      cin>>a[i];
	      if(i==0)
	        max=a[i];
	      end=end+a[i];
	      if(max<end) max=end;
	      if(end<0) end=0;
	    }
	    cout<<max<<endl;
	}
	return 0;
}*/



