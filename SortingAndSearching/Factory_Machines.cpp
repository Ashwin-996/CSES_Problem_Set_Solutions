#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#endif
 
#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define ll long long
#define vi vector<int>
#define vi2 vector<vector<int>>
#define vll vector<ll>
#define vb vector<bool>
#define mii map<int,int>
#define mci map<char,int>
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
#define all(v) v.begin(),v.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(v, x) distance(v.begin(), lower_bound(all(v), x))
#define ub(v, x) distance(v.begin(), upper_bound(all(v), x))
const int mod = 1000000007;
 
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
	f(i,0,v.size(),1)
	{
		os<<v[i];
		if(i != v.size() - 1)
			os<<" ";
	}
	return os;
}
 
bool isPrime(int n)
{
    if (n==2 || n==3)
        return true;
 
    if (n<=1 || n%2==0 || n%3==0)
        return false;
 
    for (int i=5; i*i<=n; i+=6)
    {
        if (n%i==0 || n%(i+2)==0)
            return false;
    }
 
    return true;
}
 
int n;
vll v;
 
bool p_t(ll x, ll mid)
{
	ll pt=0;
	f(i,0,n,1)
	{
		pt += mid/v[i];
		if(pt>=x) return true; 
	}
	return false;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	ll t;
	cin>>n>>t;
 
	v.resize(n);
	f(i,0,n,1)
		cin>>v[i];
 
	ll l=1;
	ll r=1e18;
	while(l<r)
	{
		ll mid = (l+r)/2;
		if(p_t(t, mid)) r=mid;
		else l=mid+1;
	}
	cout << l << endl;
 
	return 0;
}
