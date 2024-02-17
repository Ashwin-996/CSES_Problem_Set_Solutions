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
 
vi a;
vll t;
int n;
 
void build(int v, int tl, int tr)
{
	if(tl==tr)
		t[v]=a[tl];
	else
	{
		int tm = (tl+tr)/2;
		build(2*v, tl, tm);
		build(2*v+1, tm+1, tr);
		t[v] = t[2*v]^t[2*v+1];
	}
}
 
ll xor_query(int v, int tl, int tr, int l, int r)
{
	if(l>r) return 0;
	if(l==tl && r==tr) return t[v];
	int tm = (tl+tr)/2;
	return xor_query(2*v, tl, tm, l, min(tm,r))^xor_query(2*v+1, tm+1, tr, max(tm+1,l), r);
}
 
void update(int v, int tl, int tr, int pos, int new_val)
{
	if(tl==tr) t[v]=new_val;
	else
	{
		int tm = (tl+tr)/2;
		if(pos<=tm) update(2*v, tl, tm, pos, new_val);
		else update(2*v+1, tm+1, tr, pos, new_val);
		t[v] = t[2*v] + t[2*v+1];
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int q;
	cin>>n>>q;
	
	a.resize(n);
	f(i,0,n,1) cin>>a[i];
	t.resize(4*n);
 
	build(1,0,n-1);
 
	while(q--)
	{		
		int l,r;
		cin>>l>>r;
		
		cout<< xor_query(1, 0, n-1, l-1, r-1) <<"\n";
	}
 
	return 0;
}
