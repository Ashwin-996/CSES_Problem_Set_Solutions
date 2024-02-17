#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
#define m 1000000007
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n,x;
    cin>>n>>x;
 
    vector<int> c(n);
    f(i,0,n,1)
        cin>>c[i];
        
    vector<int> v(x+1);
    v[0]=1;
    f(i,1,x+1,1)
    {
        for(auto j: c)
        {
            if(i-j >= 0)
                v[i] = (v[i]+v[i-j])%m;
        }
    }
    cout<<v[x]<<"\n";
 
    return 0;
}
