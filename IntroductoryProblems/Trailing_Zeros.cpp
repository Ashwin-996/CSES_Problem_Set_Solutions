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
 
    ll n;
    cin>>n;
 
    ll div = 5;
    ll sum = 0;
    while(n/div != 0)
    {
        sum += n/div;
        div *= 5;
    } 
    cout<<sum<<"\n";
 
    return 0;
}
