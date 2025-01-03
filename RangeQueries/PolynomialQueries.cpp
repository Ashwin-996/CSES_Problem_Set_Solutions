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
 
vi arr;
 
struct node
{
	ll v, tl, tr;
	ll val, inc_val, comm_diff;
	node *left, *right;
 
	node(ll vv, ll tll, ll trr)
	{
		v=vv;
		tl=tll;
		tr=trr;
		left = nullptr;
		right = nullptr;
		inc_val = 0;
		comm_diff = 0;
		val = 0;
	}
};
 
void build(node* n)
{
	if(n->tl == n->tr) n->val = arr[n->tl];
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
 
ll ap_sum(ll a, ll n, ll d)
{
	return (n*(2*a + (n-1)*d))/2;
}
 
void push(node *n)
{
	if(n->left != nullptr)
	{
		n->left->inc_val += n->inc_val;
		n->left->comm_diff += n->comm_diff;
 
		n->left->val += ap_sum(n->inc_val, n->left->tr - n->left->tl + 1, n->comm_diff);
	}
	if(n->right != nullptr) 
	{
		ll new_val = n->inc_val + (n->left->tr - n->left->tl + 1)*n->comm_diff;
		n->right->inc_val += new_val;
		n->right->comm_diff += n->comm_diff;
 
		n->right->val += ap_sum(new_val, n->right->tr - n->right->tl + 1, n->comm_diff);
	}
 
	n->inc_val = 0;
	n->comm_diff = 0;
}
 
void inc_update(node *n, ll a, ll b, ll new_val)
{
	if(b < n->tl || a > n->tr) return;
	if(a <= n->tl && b >= n->tr) 
	{
		n->inc_val += new_val;
		n->comm_diff++;
		n->val += ap_sum(new_val, n->tr - n->tl + 1, 1);
		return;
	}
	if(n->inc_val != 0) push(n);
	inc_update(n->left, a, b, new_val);
	int x;
	if(a > n->left->tr) x = 0;
	else x = n->left->tr - max(n->left->tl, a) + 1;
	inc_update(n->right, a, b, new_val + x);
	n->val = n->left->val + n->right->val;
}
 
ll sum_query(node* n, ll a, ll b)
{
	if(b < n->tl || a > n->tr) return 0;
	if(a <= n->tl && b >= n->tr) return n->val;
	if(n->inc_val != 0) push(n);
	return sum_query(n->left, a, b) + sum_query(n->right, a, b);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,q;
	cin>>n>>q;
 
	arr.resize(n);
	f(i,0,n,1) cin>>arr[i];
 
	node *default_node = new node(1, 0, n-1);
	build(default_node);
 
	while(q--)
	{
		int num;
		ll a,b;
		cin>>num>>a>>b;
 
		if(num==1) inc_update(default_node, a-1, b-1, 1);
		else if(num==2) cout<< sum_query(default_node, a-1, b-1) <<"\n";
	}
 
	return 0;
}
