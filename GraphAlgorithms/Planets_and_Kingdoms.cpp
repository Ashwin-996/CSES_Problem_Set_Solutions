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
bool visited[100001];
stack<int> st;
vi adj2[100001];
bool processed[100001];
vector<vector<int>> scc;
vector<int> pusher;
 
void dfs(int s)
{
	if(visited[s]) return;
	visited[s] = true;
	for(auto u: adj[s]) dfs(u);
	st.push(s);
}
 
void dfs2(int s)
{
	if(processed[s]) return;
	processed[s] = true;
	for(auto u: adj2[s])
	{
		dfs2(u);
	}
	pusher.pb(s);
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
		adj2[b].pb(a);
	}
	f(i,1,n+1,1)
	{
		if(visited[i]) continue;
		dfs(i);
	}
 
	while(!st.empty())
	{
		int x = st.top(); st.pop();
		if(processed[x]) continue;
		pusher.clear();
		dfs2(x);
		scc.pb(pusher);
	}
 
	cout<< scc.size() <<"\n";
 
	mii mp;
 
	f(i,0,scc.size(),1)
	{
		f(j,0,scc[i].size(),1)
		{
			mp[scc[i][j]] = i+1;	
		}
	}
 
	f(i,1,n+1,1) cout<< mp[i] << " ";
	cout<<"\n";
 
	return 0;
}
