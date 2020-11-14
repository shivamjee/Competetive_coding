#include <iostream>
#include <vector>
#include<algorithm>
#include <cmath> 
using namespace std;



typedef long long int ll;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> values(n,-1);
        vector<int> disks(k,-1);
        for(ll i = 0;i<n;i++)
            cin>>values[i];
        for(ll i = 0;i<k;i++)
            cin>>disks[i];
        sort(disks.begin(),disks.end());
        
        
        
        ll z=0,cScore=0,gScore=0;
        while(n-1>0)
        {
            int temp = disks.size()-1;
            int flag = 0;
            while(flag == 0)
            {
                //cout<<values.size()-1<<" "<<disks[temp]<<endl;
                if(n-1>=disks[temp])
                {
                    for(ll i =0;i<disks[temp];i++)
                    {
                        if(z%2==0)
                        {
                            cScore += pow(2,values.front());
                            //cout<< values.front()<<"c";
                            values.erase(values.begin());
                            n--;
                            flag = 1;
                            
                        }
                        else
                        {
                            gScore += pow(2,values.front());
                            //cout<< values.front()<<"g";
                            values.erase(values.begin());
                            n--;
                            flag = 1;
                        }
                    }
                    //cout<<endl;
                }
                temp--;
            }
            
            z++;
        }
        //cout<<gScore<<endl;
        if(cScore>gScore)
            cout<<"Chef"<<endl;
        else
            cout<<"Garry"<<endl;
        
        
        
    }
    return 0;
}
