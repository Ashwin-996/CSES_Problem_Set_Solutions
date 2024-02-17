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
 
vi adj[100001];
int pred[100001];
 
int dfs(int s, vi &dp)
{
	if(s==1) return 1;
	if(adj[s].size()==0) return dp[s] = INT_MIN;
	if(dp[s]!=INT_MIN) return dp[s];
	for(auto u: adj[s])
	{
		ll x = dfs(u, dp)+1;
		if(x>dp[s])
		{
			dp[s] = x;
			pred[s] = u;
		}
	}
	return dp[s];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,m;
	cin>>n>>m;
 
	while(m--)
	{
		int a,b;
		cin>>a>>b;
 
		adj[b].pb(a);
	}
	vi dp(n+1, INT_MIN);
 
	int ans = dfs(n, dp);
	if(ans<=0) cout<< "IMPOSSIBLE\n";
	else
	{
		cout<< ans <<"\n";
	
		int z = n;
		vi res;
		while(pred[z]!=0)
		{
			res.pb(z);
			z = pred[z];
		}
		res.pb(1);
		for(int i = res.size()-1; i>=0; i--)
		{
			cout<<res[i];
			if(i!=0) cout<<" ";
		}
		cout<<"\n";
	}
 
	return 0;
}
