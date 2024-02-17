#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
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
 
    vector<int> v(n);
    f(i,0,n,1)
        cin>>v[i];
 
    int res=0;
    sort(v.begin(),v.end());
    int i=0;
    for(int j=n-1; j>=i; j--)
    {
        if(v[i]+v[j] <= x)
            i++;
        res++;
    }
 
    cout<<res<<"\n";
 
    return 0;
}
