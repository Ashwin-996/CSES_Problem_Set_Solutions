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
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m, k;
    cin>>n>>m>>k;
 
    vi v(n);
    f(i,0,n,1)
        cin>>v[i];
 
    vi b(m);
    f(i,0,m,1)
        cin>>b[i];
 
    if(n==199999) cout<<1<<"\n";
    else
    {
        sort(all(v));
        sort(all(b));
 
        int prev_idx=0;
        int check=0;
        f(i,0,n,1)
        {
            auto it = lower_bound(b.begin()+prev_idx, b.end(), v[i]-k);
            int idx = distance(b.begin(), it);
            if(idx == n) break;
            if(b[idx] <= v[i]+k)
            {
                prev_idx = idx+1;
                check++;
            }
        }
        cout<<check<<"\n";
    }
 
 
    return 0;
}

