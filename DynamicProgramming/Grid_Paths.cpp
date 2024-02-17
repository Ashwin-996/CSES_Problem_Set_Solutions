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
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n;
    cin>>n;
 
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));
    f(i,0,n,1)
    {
        f(j,0,n,1)
            cin>>grid[i][j];
    }
 
    dp[0][0] = 1;
    f(i,0,n,1)
    {
        f(j,0,n,1)
        {
            if((i==0 && j==0) || grid[i][j]=='*') continue;
            if(i>0)
            {
                if(grid[i-1][j]!='*')
                    dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
            }
            if(j>0)
            {
                if(grid[i][j-1]!='*')
                    dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
            }
        }
    }
    if(grid[0][0]=='*' || grid[n-1][n-1]=='*')
        cout<<0<<"\n";
    else
        cout<<dp[n-1][n-1]<<"\n";
 
    return 0;
}
