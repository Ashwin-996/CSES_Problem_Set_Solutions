#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
 
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>   
using namespace std;
using namespace chrono;
//using namespace __gnu_pbds;
 
//typedef tree<int , null_type, less<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_set; // *p.find_by_order(), p.order_of_key()
//typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset; // With find_by_order use ->fi/se and not .fi/se
//Insert as {Value, idx in original array}
// For searching p.lower_bound({Value, x}) where, x = 0 for lower_bound, x = IDX for actual find, x = INF for upper_bound
// Eg. p.erase(p.lower_bound({7, 2}))
 
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
ll phi(ll n) {ll result = n; for (ll i = 2; i * i <= n; i++) {if (n % i == 0) {while (n % i == 0) {n /= i;} result -= result / i;}} if(n > 1) {result -= result / n;} return result;}
 
const int nax = 1e5 + 2;
ll x[nax], k[nax];
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	 
	int n;
	cin>>n;
 
	ll div_num = 1;
	ll div_sum = 1;
	ll div_prod = 1;
	ll temp = 1;
	FOR(i,0,n)
	{
		cin>>x[i]>>k[i];
 
		div_num = mod_mul(div_num, k[i]+1, MOD);
		div_sum = mod_mul(div_sum, mod_div_prime(mod_pow(x[i], k[i]+1, MOD) - 1, x[i] - 1, MOD), MOD);
		div_prod = mod_mul(mod_pow(div_prod, k[i]+1, MOD), mod_pow(mod_pow(x[i], (k[i]*(k[i]+1)/2), MOD), temp, MOD), MOD);
		temp = mod_mul(temp, k[i]+1, MOD-1);
	}
 
	cout<< div_num << " " << div_sum << " " << div_prod <<nl;
 
 
	return 0;
}