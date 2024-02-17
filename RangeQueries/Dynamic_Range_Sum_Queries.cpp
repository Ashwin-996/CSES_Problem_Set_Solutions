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
 
struct node
{
	int v, tl, tr;
	ll val;
	node *left, *right;
 
	node(int vv, int tll, int trr)
	{
		v=vv;
		tl=tll;
		tr=trr;
		left = nullptr;
		right = nullptr;
	}
};
 
void build(node *n)
{
	if(n->tl == n->tr) n->val = a[n->tl];
	else
	{
		int tm = (n->tl + n->tr)/2;	
		n->left = new node(2*n->v, n->tl, tm);
		n->right = new node(2*n->v + 1, tm+1, n->tr);
		build(n->left);
		build(n->right);
		n->val = n->left->val + n->right->val;
	}
}
 
ll sum_query(node *n, int l, int r)
{
	if(l>r) return 0;
	if(l==n->tl && r==n->tr) return n->val;
	else
	{
		int tm = (n->tl + n->tr)/2;
		return sum_query(n->left, l, min(r,tm)) + sum_query(n->right, max(l,tm+1), r);
	}
}
 
void update(node *n, int pos, int new_val)
{
	if(n->tl == n->tr) n->val = new_val;
	else
	{
		int tm = (n->tl + n->tr)/2;
		if(pos<=tm) update(n->left, pos, new_val);
		else update(n->right, pos, new_val);
		n->val = n->left->val + n->right->val;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,q;
	cin>>n>>q;
 
	a.resize(n);
	f(i,0,n,1) cin>>a[i];
 
	node *default_node = new node(1, 0, n-1);
	build(default_node);
 
	while(q--)
	{
		int k,a,b;
		cin>>k>>a>>b;
		
		if(k==2) cout<< sum_query(default_node, a-1, b-1) <<"\n";
		else update(default_node, a-1, b);
	}
 
	return 0;
}
