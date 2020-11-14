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
    ll n;
    cin>>n;
    vl v;
    v.pb(0);
    rep(i,n)
    {
        ll c;
        cin>>c;
        v.pb(c);
    }
    ll mini[n+5]={0};
    mini[n]=v[n];
    for(int i=n-1;i>=1;i--)
        mini[i]=min(mini[i+1],v[i]);
    for(int i=1;i<=n;i++)
    {
        if(mini[i]==v[i])
        {
            cout<<-1<<' ';
            continue;
        }
        ll l=i+1,r=n;
        while(l<=r)
        {
            ll mid=(l+r)/2;
            if(mini[mid]<v[i])
            {
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<r-i-1<<' ';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}