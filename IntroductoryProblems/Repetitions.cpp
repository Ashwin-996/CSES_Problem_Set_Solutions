#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin>>s;
    int best = 0;
    int check = 0;
    for(int i=1; i<s.length(); ++i)
    {
        if(s[i]==s[i-1])
        {
            check++;
        }else
        {
            best = max(check, best);
            check=0;
        }
    }
    if(best > check)
    {
        cout<<best+1<<endl;
    }else
    {
        cout<<check+1<<endl;
    }
}
