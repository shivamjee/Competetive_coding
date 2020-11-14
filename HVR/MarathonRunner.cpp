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
    ll n,k;
    cin>>n>>k;
    ll A[n+1];
    for(int i=1;i<=n;i++)
        cin>>A[i];
    ll x;
    cin>>x;
    ll cost[n+1];
    for(int i=1;i<=n;i++)
        cin>>cost[i];
    multiset <ll> s;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        s.insert(cost[i]);
        while(k<A[i])
        {
            if(s.size()==0)
            {
                cout<<-1<<'\n';
                return;
            }
            auto it=s.begin();
            k+=x;
            ans+=(*it);
            s.erase(it);
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}