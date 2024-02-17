#pragma GCC optimize("O3")
#pragma GCC target("popcnt")
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
 
	vector<int> h(n+1);
	vector<int> s(n+1);
	vector<vector<int>> dp(n+1, vector<int>(x+1));
 
	f(i,1,n+1,1)
		cin>>h[i];
 
	f(i,1,n+1,1)
		cin>>s[i];
 
	f(j,0,x+1,1)
		dp[0][j] = 0;
 
	f(i,1,n+1,1)
	{
		f(j,0,x+1,1)
		{
			if(j==0)
				dp[i][j] = 0;
			else if(j>=h[i])
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-h[i]]+s[i]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[n][x]<<"\n";
 
	return 0;
}
