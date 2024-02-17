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
 
    int t;
    cin>>t;
 
    f(q,0,t,1)
    {
        int a,b;
        cin>>a>>b;
 
        if(a>2*b || b>2*a)
            cout<<"NO\n";
        else if(a==2*b || b==2*a)
            cout<<"YES\n";
        else
        {
            int moves = abs(a-b);
            if(a>b)
            {
                a -= 2*moves;
                b -= moves;
            }else if(b>a)
            {
                b -= 2*moves;
                a -= moves;
            }
            if(a%3==0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
 
    return 0;
}
