/**********************
 * Author: hvr2804
 * Competition:
 * Question:
 * Date:
**********************/

// -------SPEED UP---------
/*
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma gcc target("avx2")
*/

/*/ INCLUDED LIBRARIES /*/
/*
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <random>
#include <queue>
#include <numeric>
#include <ctime>
#include <unordered_map>
#include <bitset>
#include <unordered_set>
#include <iomanip>
*/
#include<bits/stdc++.h>
#include<chrono>
#include<random>
using namespace std;

/*/ SHORTHAND OPERATIONS /*/
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define endl "\n"
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define mod 1000000007

/*/ MODULO OPERATION /*/
/*
#define mod 998244353
*/

/*/ OPTIMIZED FUNCTIONS/*/
ll power(ll a,ll b)
{
    ll result=1;
    a%=mod;
    assert(b>=0);
    for(;b;b>>=1)
    {
        if(b&1)
            result=result*a%mod;
        a=a*a%mod;
    }
    return result;
}
ll add(ll a,ll b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
ll sub(ll a,ll b)
{
    a=a-b;
    if(a<0)
        a+=mod;
    return a;
}
ll mul(ll a,ll b)
{
    return (a*b)%mod;
}
ll modInverse(ll a)
{
    return power(a,mod-2);
}

/************************************************ Solution Begins Here *********************************************/
void solve()
{
    ll n,m,s;
    cin>>n>>m>>s;
    vector<ll> v(n,0);
    int i=0;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<ll> dp(n,0);
    dp[0]=(v[0]<=m)?1:0;
    for(i=1;i<n;i++)
    {
        if(v[i]<=m)
        {
            if(dp[i-1]==s)
            {
                dp[i]=s;
            }
            else
            {
                dp[i]=dp[i-1]+1;
            }
        }
        else
        {
            dp[i]=0;
        }
    }
    ll c=0;
    for(i=0;i<n;i++)
    {
        if(dp[i]==s)
            c++;
    }
    cout<<c<<endl;
}
int main()
{
    solve();
    return 0;
}