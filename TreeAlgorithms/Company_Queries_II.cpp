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
 
int ancestor[200005][20];
int tim_in[200005];
int tim_out[200005];
vi adj[200005];
int timer = 0;
 
void dfs(int s, int e)
{
	tim_in[s] = timer;
	timer++;
	for(auto u: adj[s])
	{
		if(u==e) continue;
		dfs(u, s);
	}
	tim_out[s] = timer;
	timer++;
}
 
bool is_ancestor(int a, int b)      
{
	if(a==-1) return true;
	return tim_in[a] < tim_in[b] && tim_out[a] > tim_out[b];
}
 
int query(int a, int b)
{
	int i = 19;
	while(i>=0)
	{
		if(is_ancestor(ancestor[b][i], a)) i--;
		else b = ancestor[b][i];
	}
	return ancestor[b][0];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,q;
	cin>>n>>q;
	
	f(i,2,n+1,1) 
	{
		cin>>ancestor[i][0];
		adj[i].pb(ancestor[i][0]);
		adj[ancestor[i][0]].pb(i);
	}
	f(j,0,20,1) ancestor[1][j] = -1;
 
	f(j,1,20,1)
	{
		f(i,2,n+1,1)
		{
			if(ancestor[i][j-1]==-1) ancestor[i][j] = -1;
			else ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
		}
	}
 
	dfs(1, -1);
	while(q--)
	{
		int a,b;
		cin>>a>>b;
 
		if(a==b) cout<< a <<"\n";
		else if(is_ancestor(a, b)) cout<< a <<"\n";
		else if(is_ancestor(b, a)) cout<< b <<"\n";
		else cout<< query(a, b) <<"\n";
	}
 
 
	return 0;
}
