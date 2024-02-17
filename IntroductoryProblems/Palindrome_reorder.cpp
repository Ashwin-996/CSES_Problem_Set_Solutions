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
 
    string s;
    cin>>s;
 
    vector<char> v;
    map<char,int> m;
 
    f(i,0,s.size(),1)
    {
        if(m[s[i]]==0)
            v.pb(s[i]);
        m[s[i]]++;
    }
 
    vector<char> res(s.size()+1);
    int check=0;
    int r=0;
    f(i,0,v.size(),1)
    {
        if(m[v[i]]%2==1)
        {
            check++;
            if(check==2)
            {
                cout<<"NO SOLUTION\n";
                break;
            }
            res[(s.size()-1)/2] = v[i];
            m[v[i]]--;
            i--;
        }else
        {
            while(m[v[i]]!=0)
            {
                res[r] = v[i];
                m[v[i]]--;
 
                res[s.size()-r-1] = v[i];
                m[v[i]]--;
 
                r++;
            }
        }
    }
    if(check!=2)
    {
        f(i,0,s.size(),1)
            cout<<res[i];
        cout<<"\n";
    }
 
    return 0;
}
