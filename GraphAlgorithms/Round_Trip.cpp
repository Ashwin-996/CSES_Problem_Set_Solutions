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
bool visited[100001];
int node = -1;
 
void dfs(int s, int e)
{
	pred[s] = e;
	if(visited[s])
	{
		node = s;
		return;
	}
	visited[s] = true;
	for(auto u: adj[s]) 
	{
		if(u==e) continue;
		dfs(u, s);
		if(node != -1) return;
	}
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
 
		adj[a].pb(b);
		adj[b].pb(a);
	}
 
	f(i,1,n+1,1)
	{
		if(visited[i]) continue;
		dfs(i, -1);
		if(node!=-1) break;
	}
 
	if(node==-1) cout<<"IMPOSSIBLE\n";
	else
	{
		stack<int> res;
		int x = pred[node];
		res.push(node);
		while(x!=node)
		{
			res.push(x);
			x = pred[x];
		}
		res.push(node);
		cout<< res.size() <<"\n";
		while(!res.empty())
		{
			cout<< res.top() <<" ";
			res.pop();
		}
		cout<<"\n";
	}
 
	return 0;
}
