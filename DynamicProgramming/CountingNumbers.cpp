#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
 
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
 
ll dp[20][10][2][2];    // digit, leftmost digit, leading_zeros, tight
 
ll solve(string b)
{
	memset(dp, 0, sizeof(dp));
 
	int n = sz(b);
	FOR(i,0,(b[n-1]-'0')+1) dp[n-1][i][0][1] = dp[n-1][i][1][1] = 1;
	FOR(i,0,10) dp[n-1][i][0][0] = dp[n-1][i][1][0] = 1;
 
	ROF(i,n-2,0)
	{
		int limit = (b[i]-'0');
		FOR(t,0,limit+1) 
		{
			FOR(d,0,10) dp[i][t][1][1] += (d==t && t) ? 0 : dp[i+1][d][(t) ? 0 : 1][(t==limit) ? 1 : 0];
			FOR(d,0,10) dp[i][t][0][1] += (d==t) ? 0 : dp[i+1][d][0][(t==limit) ? 1 : 0];
		}
		FOR(t,0,10) 
		{
			FOR(d,0,10) dp[i][t][1][0] += (d==t && t) ? 0 : dp[i+1][d][(t) ? 0 : 1][0];
			FOR(d,0,10) dp[i][t][0][0] += (d==t) ? 0 : dp[i+1][d][0][0];
		}
	}
	
	ll ret = 0;
	FOR(i,0,10) ret += dp[0][i][1][1];
 
	return ret;
}
 
int main()
{
	#ifdef FalleN
	freopen("error.txt", "w", stderr);
	#endif
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	string b;
	ll c;
	cin>>c>>b;
	c--;
 
	string a = to_string(c);
 
	cout<< solve(b) - solve(a) <<nl;
 
	 
	return 0;
}
