#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    long long int a;
    cin>>n; 
    
    vector<long long int> v;
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        v.push_back(a);
    }
    long long int check=0;
    for(int i=1; i<n; ++i)
    {
        if(v[i]<v[i-1])
        {
            while(v[i]!=v[i-1])
            {
                v[i]++;
                check++;
            }
        }
    }
    cout<<check<<endl;
}
