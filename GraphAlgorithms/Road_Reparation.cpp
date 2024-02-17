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
 
vector<int> adj[100001];
priority_queue<tuple<int,int,int>> q;
int siz[100001];
int parent[100001];
bool visited[100001];
 
void dfs(int s)
{
	if(visited[s]) return;
	visited[s] = true;
	for(auto u: adj[s]) dfs(u);
}
 
int find_set(int v) 
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
 
bool same(int a, int b)
{
	return find_set(a) == find_set(b);
}
 
void make_set(int v) {
    parent[v] = v;
    siz[v] = 1;
}
 
void union_set(int a, int b) 
{
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])
            swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
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
		ll c;
		cin>>a>>b>>c;
 
		adj[a].pb(b);
		adj[b].pb(a);
		q.push({-c,a,b});
	}
	dfs(1);
	bool check = false;
	f(i,1,n+1,1)
	{
		if(visited[i]==false)
		{
			check = true;
			break;
		}
	}
	if(check) cout<< "IMPOSSIBLE\n";
	else
	{
		f(i,1,n+1,1) make_set(i);
		ll cost = 0;
		while(!q.empty())
		{
			auto e = q.top(); q.pop();
			int a,b,w;
			tie(w,a,b) = e;
			if(!same(a,b)) 
			{
				union_set(a,b);
				cost -= w;
			}
		}
		cout<< cost <<"\n";
	}
 
	return 0;
}
