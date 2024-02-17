#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
const ll m = 1e9 + 7;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n,x;
    cin>>n>>x;
    vector<int> c;
    f(i,0,n,1)
    {
        int coi;
        cin>>coi;
        c.pb(coi);
    }
    vector<ll> v(x+1, -1);
    v[0]=0;
    f(i,1,x+1,1)
    {
        ll best=INT_MAX;
        for(auto j: c)
        {
            if(i-j >= 0)
                best=min(best, v[i-j]+1);
        }
        v[i]=best;
    }
    if(v[x]==INT_MAX)
        cout<< -1 <<"\n";
    else
        cout<< v[x] <<"\n";
 
    return 0;
}
