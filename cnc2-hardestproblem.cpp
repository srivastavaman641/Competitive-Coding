#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int

using namespace std;

ll a[105];
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll ans=0;
        for(int i=0;i<n;i++)
            ans=__gcd(ans,a[i]);
        if(ans==1)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
