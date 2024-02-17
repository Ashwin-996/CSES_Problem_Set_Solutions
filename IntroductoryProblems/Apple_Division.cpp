#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
const ll m = 1e9 + 7;
 
int n;
vector<ll> v;
ll sum1=0;
ll sum2=0;
ll best=INT_MAX;
 
void solve(int i)
{
    if(i==n)
        best = min(best,abs(sum1-sum2));
    else
    {
        sum1 += v[i];
        solve(i+1);
        sum1 -= v[i];
        sum2 += v[i];
        solve(i+1);
        sum2 -= v[i];
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
 
    v.resize(n);
    f(i,0,n,1)
        cin>>v[i];
    
    solve(0);
    cout<<best<<"\n";
 
    return 0;
}
