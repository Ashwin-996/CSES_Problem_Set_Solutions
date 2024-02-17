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
 
int n,m;
vector<bool> visited(1, false);
 
void dfs(int i, vi adj[])
{
    if(visited[i])
        return;
    visited[i]=true;
    for(auto u: adj[i])
        dfs(u, adj);
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n>>m;  
 
    vi adj[n+1];
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    visited.resize(n+1);
    int check=0;
    vi v;
    f(i,1,n+1,1)
    {
        if(visited[i]) continue;
        dfs(i, adj);
        v.pb(i);
        check++;
    }
    cout<<check-1<<"\n";
    f(i,0,v.size()-1,1)
        cout<<v[i]<<" "<<v[i+1]<<"\n";
 
 
    return 0;
}
