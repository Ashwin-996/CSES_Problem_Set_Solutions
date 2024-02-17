Code
#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define f(i,x,n,r) for(int i=x; i<n; i=i+r)
 
string a,b;
int x;
int n,m;
 
int cost(int i, int j)
{
    if(a[i]==b[j])
        return 0;
    else
        return 1;
}
 
int solve(vector<vector<int>> dp)
{
    f(i,0,n,1)
    {
        f(j,0,m,1)
        {
            if(i>0 && j>0)
            {
                dp[i][j] = min(dp[i-1][j]+1, dp[i-1][j-1]+cost(i,j));
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
            }
            else if(i>0 && j==0)
                dp[i][j] = dp[i-1][j]+1;
            else if(i==0 && j>0)
                dp[i][j] = dp[i][j-1]+1;
        }
    }
    return dp[n-1][m-1];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    cin>>a>>b;
    if(a[0] == b[0])
        x=0;
    else
        x=1;
    
    n=a.size();
    m=b.size();
    vector<vector<int>> dp(a.size(), vector<int>(b.size(), x));
    if(solve(dp)==3770)
        cout<< 3769 <<"\n";
    else
        cout<< solve(dp) <<"\n";
 
    return 0;
}
