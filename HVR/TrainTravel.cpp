#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
void solve()
{
    ll n,x;
    cin>>n>>x;
    ll oneside=x-1;
    for(int i=1;i<=n;i++)
    {
        ll b,e,t;
        cin>>b>>e>>t;
        if(b==e)
        {
            cout<<t<<'\n';
            continue;
        }
        ll init=t;
        t%=(2*oneside);
        init-=t;
        if(b<e)
        {
            if(t<=(b-1))
            {
                t=e-1;
            }
            else
            {
                t=(2*oneside)+e-1;
            }
        }
        else
        {
            if(t<=(oneside+x-b))
            {
                t=oneside+x-e;
            }
            else
            {
                t=(3*oneside+x-e);
            }
        }
        cout<<init+t<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}