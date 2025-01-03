#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace chrono;
//using namespace __gnu_pbds;
 
#define ll long long
 
//typedef tree<int , null_type, less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set; // *p.find_by_order(), p.order_of_key()
//typedef tree<pair<ll, int>, null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // With find_by_order and use ->fi/se and not .fi/se
//Insert as {Value, idx in original array}
// For searching p.lower_bound({Value, x}) where, x = 0 for lower_bound, x = IDX for actual find, x = INF for upper_bound
// Eg. p.erase(p.lower_bound({7, 2}))
 
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define ld long double
#define vi vector<int>
#define vi2 vector<vector<int>>
#define vll vector<ll>
#define vll2 vector<vector<long long>>
#define vb vector<bool>
#define mii map<int,int>
#define mci map<char,int>
#define pii pair<int,int>
#define FOR(i,x,n) for(int i=x; i<n; i++)
#define ROF(i,x,n) for(int i=x; i>=n; i--)
#define trav(u, v) for(auto &u: v)
#define all(v) v.begin(),v.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(v, x) distance(v.begin(), lower_bound(all(v), x))
#define ub(v, x) distance(v.begin(), upper_bound(all(v), x))
#define INF LLONG_MAX
#define CEIL(a, b) (a+b-1)/b
#define sz(x) ((int)x.size())
#define um unordered_map
#define nl "\n"
const int MOD = 1000000007;
//const int MOD = 998244353;
 
#ifdef FalleN
#include "debugger.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...) 2
#endif
 
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);}
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//unordered_map<long long, int, custom_hash> safe_map;
 
void add_self(ll &a, ll b)
{
	a += b;
	if(a >= MOD) a -= MOD;
}
 
ll ext_gcd(ll a, ll b, ll &x, ll &y) {if(!b) {x = 1; y = 0; return a;} ll x1, y1; ll gc = ext_gcd(b, a % b, x1, y1); x = y1; y = x1 - y1 * (a / b); return gc;}
ll mod_pow(ll x, ll n, ll m) {if(!n) return 1%m; ll u = mod_pow(x,n/2,m); u = (u*u)%m; if(n%2) u = (u*x)%m; return u;}
ll mod_inv(ll a, ll m) {ll x,y; ll gc = ext_gcd(a, m, x, y); assert(gc == 1LL); x = (x % m + m) % m; return x;}
ll mod_inv_prime(ll a, ll m) {return mod_pow(a, m-2, m);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;} 
ll mod_div_prime(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv_prime(b, m), m) + m) % m;}  
ll phi(ll n) {ll result = n; for (ll i = 2; i * i <= n; i++) {if (!(n % i)) {while (!(n % i)) {n /= i;} result -= result / i;}} if(n > 1) {result -= result / n;} return result;}
 
bool multi_test_cases = 0;
 
vll arr;
 
struct node
{
	int v, tl, tr;
	ll l,r;
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
	if(n->tl == n->tr) {n->l = arr[n->tl] - n->tl; n->r = arr[n->tl] + n->tl;}
	else
	{
		int tm = (n->tl + n->tr)/2;	
		n->left = new node(2*n->v, n->tl, tm);
		n->right = new node(2*n->v + 1, tm+1, n->tr);
		build(n->left);
		build(n->right);
		n->l = min(n->left->l, n->right->l);
		n->r = min(n->left->r, n->right->r);
	}
}
 
void update_query(node *n, int pos, ll new_val)
{
	if(n->tl == n->tr) {n->l = new_val - n->tl; n->r = new_val + n->tl;}
	else
	{
		int tm = (n->tl + n->tr)/2;
		if(pos<=tm) update_query(n->left, pos, new_val);
		else update_query(n->right, pos, new_val);
		n->l = min(n->left->l, n->right->l);
		n->r = min(n->left->r, n->right->r);
	}
}
 
ll query(node *n, int x, int y, bool flag)
{
	if(x>y) return INF;
	if(x==n->tl && y==n->tr) return ((flag) ? n->r : n->l);
	else
	{
		int tm = (n->tl + n->tr)/2;
		return min(query(n->left, x, min(y,tm), flag), query(n->right, max(x,tm+1), y, flag));
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int t = 1;
	if(multi_test_cases) cin>>t;
 
	while(t--)
	{
		int n,q;
		cin>>n>>q;
	 
		arr.resize(n);
		FOR(i,0,n) cin>>arr[i];
	 
		node *default_node = new node(1, 0, n-1);
		build(default_node);
	 
		while(q--)
		{
			int num;
			ll a;
			cin>>num>>a;
 
			if(num==1)
			{
				ll x;
				cin>>x;
 
				update_query(default_node, a-1, x);
				arr[a-1] = x;
			}else 
			{
				ll le = INF;
				ll ri = INF;
 
				if(a > 1) le = query(default_node, 0, a-2, 0) + (a-1);
				if(a < n) ri = query(default_node, a, n-1, 1) - (a-1);
 
				cout<< min(min(le, ri), arr[a-1]) <<nl;
			}
		}
	}
 
 
	return 0;
}