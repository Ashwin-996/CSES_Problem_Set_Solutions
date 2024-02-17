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
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int a,b;
	cin>>a>>b;
 
	vector<vector<ll>> dp(max(a+1, b+1), vll(max(a+1, b+1), INT_MAX));
 
	f(i,1,a+1,1) dp[i][1] = i-1;
	f(j,1,b+1,1) dp[1][j] = j-1;
	f(i,1,max(a+1,b+1),1) dp[i][i] = 0;
 
	f(i,2,max(a+1, b+1),1)
	{
		f(j,2,max(a+1, b+1),1)
		{
			f(k,1,max(i,j),1)
			{
				if(i==j) continue;
				if(k<j) dp[i][j] = min(dp[i][j], dp[i][j-k] + dp[i][k] + 1);
				if(k<i) dp[i][j] = min(dp[i][j], dp[i-k][j] + dp[k][j] + 1);
			}
		}
	}
	cout<< dp[a][b] <<"\n";
 
	return 0;
}
