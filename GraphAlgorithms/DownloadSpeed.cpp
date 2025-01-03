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
#define vll2 vector<vector<long long>>
#define vb vector<bool>
#define mii map<int,int>
#define mci map<char,int>
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
#define trav(u, v) for(auto &u: v)
#define all(v) v.begin(),v.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(v, x) distance(v.begin(), lower_bound(all(v), x))
#define ub(v, x) distance(v.begin(), upper_bound(all(v), x))
#define INF_I INT_MAX
#define INF_L LLONG_MAX
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
 
ll n,m;
vb visited;
vi2 adj;
vll2 capacity;
bool found = false;
ll bound = 0;
ll sub = 0;
ll flow = 0;
int src;
int tgt;
 
void dfs(int s, ll mini)
{
	if(visited[s]) return;
	visited[s] = 1;
 
	trav(u, adj[s]) 
	{
		if(capacity[s][u] >= bound) 
		{
			mini = min(mini, capacity[s][u]);
			if(u == tgt)
			{
				found = 1;
				sub = mini;
				capacity[s][u] -= sub;
				capacity[u][s] += sub;
				flow += sub;
				return;
			}
			dfs(u, mini);
		}
		if(found) 
		{
			capacity[s][u] -= sub;
			capacity[u][s] += sub;
			return;
		}
	}
}
 
ll max_flow()
{
	while(bound > 0)
	{
		dfs(src, INF_L);
		fill(all(visited), 0);
		if(!found) bound /= 2;
		found = 0;
	}
 
	return flow;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin>>n>>m;
 
	src = 0;
	tgt = n-1;
 
	visited.resize(n);
	adj.resize(n);
	capacity.resize(n, vll(n));
 
	while(m--)
	{
		int a,b;
		ll c;
		cin>>a>>b>>c;
 
		adj[a-1].pb(b-1);
		adj[b-1].pb(a-1);
		capacity[a-1][b-1] += c;
		bound += c;
	}
 
	cout<< max_flow() <<"\n";
 
	return 0;
}
