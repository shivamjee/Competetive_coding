#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=100023;
bool vis[N];
vector <int> adj[N];
ll n,q;
ll fastmax(ll x, ll y) { return (((y-x)>>(62))&(x^y))^y; }
ll fastmax3(ll a,ll b,ll c)
{
    return fastmax(fastmax(a,b),c);
}
void solve()
{
    cin>>n>>q;
    ll val[n+1];
    ll color[n+1];
    for(int i=0;i<n;i++)
        cin>>val[i];
    for(int i=0;i<n;i++)
    {
        cin>>color[i];
        color[i]--;
    }
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        ll dp[n+1];
        vector <pair<ll,ll>> v;
        v.pb(mp(-1e18,0));
        v.pb(mp(-1e18,0));
        for(int i=0;i<=n;i++)
        {
            dp[i]=-1e18;
        }
        for(int i=0;i<n;i++)
        {
            ll col=color[i];
            ll a=val[i];
            ll fun;
            if(v[1].second==col)
                fun=v[0].first;
            else
                fun=v[1].first;
            if(fun==-1e18)
            {
                dp[col]=fastmax3(dp[col],dp[col]+a*x,a*y);
            }
            else
            {
                dp[col]=fastmax3(dp[col],dp[col]+a*x,fun+a*y);
                dp[col]=fastmax(dp[col],a*y);
            }
            if(v[1].second==col)
                v[1].first=dp[col];
            else
            {
                if(v[0].first<dp[col])
                {
                    v[0]=mp(dp[col],col);
                    if(v[0].first>v[1].first)
                        reverse(all(v));
                }
            }
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans=fastmax(ans,dp[i]);
        }
        cout<<ans<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}