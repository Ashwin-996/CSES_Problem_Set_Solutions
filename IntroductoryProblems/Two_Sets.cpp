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
 
    int n;
    cin>>n;
 
    if(n%2==0 && n%4!=0)
        cout<<"NO\n";
    else if(n%4==0)
    {
        cout<<"YES\n";
        int i=1;
        int j=0;
        int x=n/4;
        vector<int> v1;
        vector<int> v2;
        while(i<(n+1))
        {
            if(j%2==0)
                v1.pb(i);
            else
                v2.pb(i);
            if(i==x || i==3*x)
                j++;
            i++;
        }
        cout<<n/2<<"\n";
        f(i,0,(n/2)-1,1)
            cout<<v1[i]<<" ";
        cout<<v1[(n/2)-1]<<"\n";
 
        cout<<n/2<<"\n";
        f(i,0,(n/2)-1,1)
            cout<<v2[i]<<" ";
        cout<<v2[(n/2)-1]<<"\n";
    }else if(n%4==1)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        int i=1;
        vector<int> v1;
        vector<int> v2;
        int j=0;
        while(i<(n+1))
        {
            if(j%2==0)
            {
                v1.pb(i);
                i++;
                v1.pb(i);
                i++;
            }else
            {
                v2.pb(i);
                i++;
                if(i==n+1)
                    break;
                v2.pb(i);
                i++;
            }
            j++;
        }
        cout<<(n+1)/2<<"\n";
        f(i,0,((n+1)/2)-1,1)
            cout<<v1[i]<<" ";
        cout<<v1[((n+1)/2)-1]<<"\n";
 
        cout<<(n-1)/2<<"\n";
        f(i,0,((n-1)/2)-1,1)
            cout<<v2[i]<<" ";
        cout<<v2[((n-1)/2)-1]<<"\n";
    }
 
    return 0;
}
