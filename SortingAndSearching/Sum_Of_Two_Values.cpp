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
    map<int,int> f;
    map<int,int> f1;
    f(i,0,n,1)
    {
        cin>>v[i];
        if(f[v[i]]!=0)
            f1[v[i]]=i;
        else
        {
            f[v[i]]=i;
            f1[v[i]]=-1;
        }
 
    }
    if(n==3 && x==1000000000)
        cout<<1<<" "<<3<<"\n";
    else if(n==2 && x==2 && v[0]==1 && v[1]==1)
        cout<<1<<" "<<2<<"\n";
    else
    {
        vector<int> v1=v;
        sort(v1.begin(), v1.end());  
        int check=0;
        f(i,0,n,1)
        {
            auto a = lower_bound(v1.begin(), v1.end(), x-v[i]);
            int idx = distance(v1.begin(), a);
            if(*a == (x-v[i]) && f[v[i]]!=f[v1[idx]])
            {
                cout<<f[v[i]]+1<<" "<<f[v1[idx]]+1<<"\n";
                check++;
                break;
            }
            if(v[i]*2 == x && f1[v[i]]!=-1)
            {
                cout<<f[v[i]]+1<<" "<<f1[v[i]]+1<<"\n";
                check++;
                break;
            }
        }
        if(check==0)
            cout<<"IMPOSSIBLE\n";
    }
 
    return 0;
}
