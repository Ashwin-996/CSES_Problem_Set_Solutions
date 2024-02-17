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
 
vll dist;
vector<bool> processed(1, false);
int n;
 
void dijkstra(int i, vector<vector<pair<ll,ll>>> adj)
{
    f(i,1,n+1,1) dist[i] = INFINITY;
    priority_queue<pair<ll,ll>> q;    
    dist[i]=0;
    q.push({0,i});
    while(!q.empty())
    {
        ll a=q.top().se; q.pop();
        if(processed[a]) continue;
        processed[a]=true;
        for(auto u: adj[a])
        {
            ll b = u.fi, w = u.se;
            dist[b] = min(dist[b], dist[a]+w);
            q.push({-dist[b], b});
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int m;
    cin>>n>>m;
    dist.resize(n+1);
    processed.resize(n+1);
 
    vector<vector<pair<ll,ll>>> adj(n+1);
    while(m--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dijkstra(1, adj);
    f(i,1,n+1,1)
    {
        cout<<dist[i];
        if(i!=n) cout<<" ";
    }
    cout<<"\n";
 
    return 0;
}
