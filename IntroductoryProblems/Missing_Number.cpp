#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n,p;
    cin>>n;
    
    vector<int> v;
    for(int i=0; i<(n-1); ++i)
    {
        cin>>p;
        v.push_back(p);
    }
    sort(v.begin(),v.end());
    int check=0;
    for(int i=0; i<(n-1); ++i)
    {
        if(v[i] != (i+1))
        {
            cout<<(i+1)<<endl;
            check++;
            break;
        }
    }
    if(check==0)
    {
        cout<< v[n-2] + 1 <<endl;
    }
    
    return 0;
}
