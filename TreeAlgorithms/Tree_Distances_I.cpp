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
 
int firstMax[200001];
int secondMax[200001];
int c[200001];
vi adj[200001];
 
void dfs(int curr, int prev)
{
	firstMax[curr] = 0;
	secondMax[curr] = 0;
	for(auto u: adj[curr])
	{
		if(u == prev) continue;
		dfs(u, curr);
		if(firstMax[u]+1 > firstMax[curr])
		{
			secondMax[curr] = firstMax[curr];
			firstMax[curr] = firstMax[u]+1;
			c[curr] = u;
		}else if(firstMax[u]+1 > secondMax[curr]) 
		{
			secondMax[curr] = firstMax[u]+1;
		}
	}
}
 
void dfs2(int curr, int prev)
{
	for(auto u: adj[curr])
	{
		if(u == prev) continue;
		if(c[curr] == u)
		{
			if(secondMax[curr]+1 > firstMax[u])
			{
				secondMax[u] = firstMax[u];
				firstMax[u] = secondMax[curr]+1;
				c[u] = curr;
			}else secondMax[u] = max(secondMax[u], secondMax[curr]+1);
		}else
		{
			secondMax[u] = max(firstMax[u], secondMax[curr]+1);
			firstMax[u] = firstMax[curr]+1;
			c[u] = curr;
		}
		dfs2(u, curr);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n;
	cin>>n;
 
	f(i,0,n-1,1)
	{
		int a,b;
		cin>>a>>b;
 
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	dfs(1,-1);
	dfs2(1,-1);
 
	f(i,1,n+1,1) cout<< firstMax[i] <<" ";
	cout<<"\n";
 
	return 0;
}
