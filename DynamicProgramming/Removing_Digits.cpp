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
    int x=n;
 
    int check=0;
    while(n!=0)
    {
        vector<int> digits;
        while(x!=0)
        {
            digits.pb(x%10);
            x=x/10;
        }
        n -= *max_element(digits.begin(), digits.end());
        x=n;
        check++;
    }
    cout<<check<<"\n";
 
    return 0;
}
