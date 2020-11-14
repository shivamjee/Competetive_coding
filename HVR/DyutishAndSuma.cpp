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
    ll ans1=0;
    ll ans2=0;
    ll n=0;
    cin>>n;
    ll arr[n];
    ll i=0;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int l=0;
    int r=n-1;
    int c=0;
    while(l<=r)
    {
		if(c)
		{
			c^=1;
			if(arr[l]>arr[r])
			{
				ans1=ans1+arr[l++];
			}
			else
			{
				ans1+=arr[r--];
			}
		}
		else
		{
			c^=1;
			if(arr[l]>arr[r])
			{
				ans2+=arr[l++];
			}
			else
			{
				ans2+=arr[r--];
			}
		}
    }
    cout<<ans2<<" "<<ans1<<endl;
}
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}