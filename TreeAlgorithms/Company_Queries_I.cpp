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
 
int ancestor[200005][20];
 
int query(int x, int k)
{
	for(int i=19; i>=0; i--)
	{
		if(k & (1<<i)) x = ancestor[x][i];
		if(x==-1) break;
	}
	return x;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	int n,q;
	cin>>n>>q;
	
	f(i,2,n+1,1) cin>>ancestor[i][0];
	f(j,0,20,1) ancestor[1][j] = -1;
 
	f(j,1,20,1)
	{
		f(i,2,n+1,1)
		{
			if(ancestor[i][j-1]==-1) ancestor[i][j] = -1;
			else ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
		}
	}
 
	while(q--)
	{
		int x,k;
		cin>>x>>k;
 
		cout<< query(x, k) <<"\n";
	}
 
 
	return 0;
}

