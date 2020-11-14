#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define mod 997
#define rep(i,n) for(ll i=0;i<n;i++)
#define vl vector <ll>
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=400023;
bool vis[N];
vector <int> adj[N];
ll fact[N];
ll invfact[N];
ll inv[N];
void factorialsComputation()
{
    inv[0]=inv[1]=1;
    fact[0]=fact[1]=1;
    invfact[0]=invfact[1]=1;
    for(int i=2;i<N;i++)
    {
        inv[i]=modInverse(i);
        if((i%mod)==0)
        {
            ll temp=i;
            while(temp%mod==0)
                temp/=mod;
            fact[i]=(fact[i-1]*temp)%mod;
            invfact[i]=(invfact[i-1]*inv[temp])%mod;
        }
        else
        {
            fact[i]=(fact[i-1]*i)%mod;
            invfact[i]=(invfact[i-1]*inv[i])%mod;
        }
    }
}
ll ncr(ll n,ll r)
{
    ll temp=fact[n];
    temp*=invfact[r];
    temp%=mod;
    temp*=invfact[n-r];
    temp%=mod;
    return temp;
}
void solve()
{
    ll n,k,x;
    cin>>n>>k>>x;
    x=min(x,n-x);
    ll type[k+1]={0};
    for(int i=1;i<=n;i++)
    {
        ll c;
        cin>>c;
        type[c]++;
    }
    ll dp[2*n+1]={0};
    dp[0]=1;
    for(int i=1;i<=k;i++)
    {
        ll p=type[i]+1;
        for(int j=x;j>=p;j--)
        {
            dp[j]-=dp[j-p];
            dp[j]+=mod;
            dp[j]%=mod;
        }
    }
    ll ans=0;
    ll fun[k+x+1];
    for(int i=0;i<=k+x;i++)
        fun[i]=(i/mod)+(i/(mod*mod));
    for(int i=0;i<=x;i++)
    {
        if(fun[k+i-1]>fun[i]+fun[k-1])
            continue;
        assert(fun[k+i-1]==fun[i]+fun[k-1]);
        ll temp=ncr(k+i-1,i)*dp[x-i];
        ans+=temp;
        ans%=mod;
    }
    cout<<ans<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorialsComputation();
    solve();
}