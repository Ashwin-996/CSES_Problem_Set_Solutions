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
 
queue<int> q;
vector<bool> visited(1, false);
vi res;
int check=0;
int n;
vi dist(1, -1);
vi pred(1, 0);
 
bool bfs(vi adj[])
{
    visited[1]=true;
    q.push(1);
    dist[1]=0;
    pred[1]=-1;
    while(!q.empty())
    {
        int s = q.front(); q.pop();
        for(auto u: adj[s])
        {
            if(visited[u]==true) continue;
            dist[u] = dist[s]+1;
            q.push(u);
            visited[u]=true;
            pred[u]=s;
            if(u==n)
                return true;
        }
    }
    return false;
}
 
void sh(vi adj[])
{
    if(bfs(adj)==false)
        cout<<"IMPOSSIBLE\n";
    else
    {
        int x=n;
        res.pb(x);
        while(pred[x]!=-1)
        {
            res.pb(pred[x]);
            x=pred[x];
        }
        cout<<res.size()<<"\n";
        for(int i=res.size()-1; i>=0; i--)
        {
            cout<<res[i];
            if(i!=0)
                cout<<" ";
        }
        cout<<"\n";
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
    visited.resize(n+1);
    pred.resize(n+1);
 
    vi adj[n+1];
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    sh(adj);
    
    return 0;
}
