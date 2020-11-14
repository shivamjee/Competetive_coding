#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<vector<int> > vec(n,vector<int>(n,0));
	    for(int i=0;i<n;i++)
	        for(int j =0;j<n;j++)
	            cin>>vec[i][j];
        int i=0,j=0,sum=0;
        while(i!=n-1||j!=n-1)
        {
            sum+= vec[i][j];
            vector<int> arr(4);

            arr[0] = i-1<0?10001:(vec[i-1][j]==10001?10001:vec[i-1][j]);
            arr[1] = i+1>n-1?10001:(vec[i+1][j]==10001?10001:vec[i+1][j]);
            arr[2] = j-1<0?10001:(vec[i][j-1]==10001?10001:vec[i][j-1]);
            arr[3] = j+1>n-1?10001:(vec[i][j+1]==10001?10001:vec[i][j+1]);
            int index = min_element(arr.begin(),arr.end())-arr.begin();
            //cout<<index<<" ";


            vec[i][j] = 10001;  //changed


            if(index == 0)
                i = i-1;
            else if(index == 1)
                i = i+1;
            else if(index == 2)
                j = j-1;
            else
                j = j+1;
            if(i==n-1&& j ==n-1)
                break;
        }
        sum+= vec[n-1][n-1];
        cout<<sum<<endl;
	}
	return 0;
}

