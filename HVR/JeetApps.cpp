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
ll mini=1e18;
ll val[N]={0};
void dfs(int curr)
{
    vis[curr]=1;
    mini=min(mini,val[curr]);
    for(auto it:adj[curr])
    {
        if(vis[it])
            continue;
        dfs(it);
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>val[i];
    for(int i=1;i<=m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
            continue;
        mini=1e18;
        dfs(i);
        ans+=mini;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}