#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    
    if(n==1)
    {
        cout<<1<<endl;
    }else if(n<4 && n>1)
    {
        cout<<"NO SOLUTION"<<endl;
    }else
    {
        vector<int> v;
        v.resize(n);
        for(int i=0; i<(n/2); ++i)
        {
            v[i] = (i+1)*2;
        }
        int j=1;
        for(int i=(n/2); i<n; ++i)
        {
            v[i] = j;
            j=j+2;
        }
        for(int i=0; i<n; ++i)
        {
            cout<< v[i] <<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
