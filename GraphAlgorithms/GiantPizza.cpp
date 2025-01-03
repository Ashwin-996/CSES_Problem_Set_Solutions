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
 
vector<bool> visited;
vi res;
int check = 0;
 
void dfs_1(int s, vi adj[])
{
	if(visited[s]) return;
	visited[s] = true;
	for(auto &u: adj[s]) dfs_1(u, adj);
	res.pb(s);
}
 
vi component;
 
void dfs_2(int s, vi adj[])
{
	if(visited[s]) return;
	visited[s] = true;
	component[s] = check;
	for(auto &u: adj[s]) dfs_2(u, adj);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,m;
	cin>>n>>m;
	visited.resize(2*m);
 
	vi adj[2*m];
	vi rev_adj[2*m];
	f(i,0,n,1)
	{
		char s1,s2;
		int idx_1, idx_2;
		cin>>s1>>idx_1>>s2>>idx_2;
 
		idx_1--;
		if(s1=='-') idx_1 += m;
		idx_2--;
		if(s2=='-') idx_2 += m;
 
		adj[(idx_1 + m)%(2*m)].pb(idx_2);
		adj[(idx_2 + m)%(2*m)].pb(idx_1);
 
		rev_adj[idx_2].pb((idx_1 + m)%(2*m));
		rev_adj[idx_1].pb((idx_2 + m)%(2*m));
	}
 
	f(i,0,2*m,1)
	{
		if(visited[i]) continue;
		dfs_1(i, adj);
	}
 
	f(i,0,2*m,1) visited[i] = false;
 
	component.resize(2*m);
	for(int i = (int)res.size() - 1; i >= 0; i--)
	{
		if(visited[res[i]]) continue;
		check++;
		dfs_2(res[i], rev_adj);
	}
 
	vector<bool> ans(m, 0);
	bool imp = 0;
	f(i,0,m,1)
	{
		if(component[i]==component[i+m])
		{
			imp = 1;
			break;
		}
		if(component[i] > component[i+m]) ans[i] = 1;
	}
	
	if(imp) cout<< "IMPOSSIBLE\n";
	else
	{
		f(i,0,m,1)
		{
			if(ans[i]) cout<< "+ ";
			else cout<< "- ";
		}
		cout<<"\n";
	}
	
 
	return 0;
}
