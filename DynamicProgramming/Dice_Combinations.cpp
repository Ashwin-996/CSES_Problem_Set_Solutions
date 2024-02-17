#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
const ll m = 1e9+7;
 
int n;
vector<ll> v;
 
ll solve()
{
    v[1]=1;
    f(i,2,n+1,1)
    {
        f(j,1,7,1)
        {
            if(i-j > 0)
            {
                v[i] = (v[i]+v[i-j])%m;
                
            }
        }
        if(i<7)
        {
            v[i]++;
        }
    }
    return v[n]%m;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>n;
    v.resize(n+1);
    cout<<solve()<<"\n";
 
    return 0;
}
