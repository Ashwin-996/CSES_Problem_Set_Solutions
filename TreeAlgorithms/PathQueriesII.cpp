#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>   
using namespace std;
//using namespace chrono;
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
#define vpii vector<pii>
#define FOR(i,x,n) for(int i=x; i<n; i++)
#define ROF(i,x,n) for(int i=x; i>=n; i--)
#define trav(u, v) for(auto &u: v)
#define all(v) v.begin(),v.end()
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define lb(v, x) dist(v.begin(), lower_bound(all(v), x))
#define ub(v, x) dist(v.begin(), upper_bound(all(v), x))
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
 
const int nax = 2e5 + 5;
int n;
int parent[nax];
int depth[nax];
int heavy[nax];
int head[nax];
int vals[nax];
int arr[nax];
int t[2*nax];
int	pos[nax];
vi adj[nax];
int cur_idx = 0;
 
void max_self(int &a, int b)
{
	a = max(a, b);
}
 
void build()
{
	FOR(i,0,n) t[n+i] = arr[i];
	ROF(i,n-1,1) t[i] = max(t[2*i], t[2*i+1]);
}
 
int max_query(int l, int r)
{
	l += n; r += n;
 
	int maxi = INT_MIN;
	while(l < r)
	{
		if(l&1) max_self(maxi, t[l++]);
		if(r&1) max_self(maxi, t[--r]);
 
		l /= 2;
		r /= 2;
	}
 
	return maxi;
}
 
void update(int posi, int new_val)
{
	posi += n;
	t[posi] = new_val;
	while(posi > 1)
	{
		posi /= 2;
		t[posi] = max(t[2*posi], t[2*posi+1]);
	}
}
 
int dfs(int s) 
{
    int siz = 1;
    int max_child_size = 0;
	trav(u, adj[s])
	{
		if(u==parent[s]) continue;
 
		parent[u] = s;
		depth[u] = depth[s] + 1;
		int child_size = dfs(u);
		siz += child_size;
		if(child_size > max_child_size) {max_child_size = child_size; heavy[s] = u;}
    }
 
    return siz;
}
 
void decompose(int s, int h) 
{
    head[s] = h;
	arr[cur_idx] = vals[s];
	pos[s] = cur_idx; cur_idx++;
    if(heavy[s] != -1) decompose(heavy[s], h);
    trav(u, adj[s]) 
	{
        if(u != parent[s] && u != heavy[s]) decompose(u, u);
    }
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int tt = 1;
	if(multi_test_cases) cin>>tt;
 
	while(tt--)
	{
		int q;
		cin>>n>>q;
 
		FOR(i,0,n) cin>>vals[i];
 
		FOR(i,0,n-1)
		{
			int a,b;
			cin>>a>>b;
 
			adj[a-1].pb(b-1);
			adj[b-1].pb(a-1);
		}
 
		FOR(i,0,n) heavy[i] = -1;
		dfs(0);
		decompose(0,0);
 
		build();
 
		while(q--)
		{
			int num,a,b;
			cin>>num>>a>>b;
 
			if(num==1) update(pos[a-1], b);
			else 
			{
				a--; b--;
				int res = 0;
				for(; head[a] != head[b]; b = parent[head[b]]) 
				{
					if(depth[head[a]] > depth[head[b]]) swap(a, b);
					int heavy_max = max_query(pos[head[b]], pos[b]+1);
					res = max(res, heavy_max);
				}
				if(depth[a] > depth[b]) swap(a, b);
				int heavy_max = max_query(pos[a], pos[b]+1);
				res = max(res, heavy_max);
 
				cout<< res << " ";
			}
		}
		cout<<nl;
	}
 
 
	return 0;
}
 
