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
int affected[N];
ll subtree[N];
ll par[N];
ll n,k,r;
multiset <ll> at[N];
int level[N]={0};
void dfs(int curr)
{
    vis[curr]=1;
    for(int i:adj[curr])
    {
        if(vis[i])
            continue;
        dfs(i);
        par[i]=curr;
        if(subtree[i]!=-1)
            subtree[curr]=max(subtree[curr],subtree[i]+1);
    }
    if(affected[curr]==1)
        subtree[curr]=max(subtree[curr],(ll)0);
}
void dfs2(int curr)
{
    vis[curr]=1;
    if(curr==1)
    {
        for(int i:adj[curr])
        {
            if(subtree[i]!=-1)
                at[curr].insert(subtree[i]+1);
        }
        if(affected[curr])
            at[curr].insert(0);
        for(int i:adj[curr])
            dfs2(i);
    }
    else
    {
        for(auto it:adj[curr])
        {
            if(it==par[curr])
            {
                ll rem=-1;
                if(subtree[curr]!=-1)
                {
                    rem=subtree[curr]+1;
                }
                if(rem==-1)
                {
                    at[curr].insert((*(at[it].rbegin()))+1);
                }
                else
                {
                    if(at[it].size()==1)
                    {

                    }
                    else
                    {
                        auto iter=at[it].end();
                        iter--;
                        if((*iter)==rem)
                        {
                            iter--;
                        }
                        at[curr].insert((*iter)+1);
                    }
                }
            }
            else
            {
                if(subtree[it]!=-1)
                    at[curr].insert(subtree[it]+1);
            }
        }
        if(affected[curr])
            at[curr].insert(0);
        for(auto it:adj[curr])
        {
            if(vis[it])
                continue;
            dfs2(it);
        }
    }
}
void fun(int curr)
{
    vis[curr]=1;
    for(int i:adj[curr])
    {
        if(vis[i])
            continue;
        level[i]=level[curr]+1;
        fun(i);
    }
}
void solve()
{
    cin>>n>>k>>r;
    for(int i=1;i<=k;i++)
    {
        ll c;
        cin>>c;
        affected[c]=1;
    }
    for(int i=1;i<=n;i++)
        subtree[i]=-1;
    for(int i=1;i<=n-1;i++)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    for(int i=1;i<=n;i++)
        vis[i]=0;
    dfs2(1);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(((*at[i].rbegin())<=r))
            ans++;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}