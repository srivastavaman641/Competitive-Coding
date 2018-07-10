#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod = 1e9+7;
ll power(ll x,ll y)
{
    ll res = 1;
    x=x%mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x)%mod;
        y = y>>1;
        x = (x*x)%mod;
    }
    return res;
}

int main(){
    ll x,k;
    ll ans;
    cin>>x>>k;
    k++;
    if(x==0)
    {
        cout<<0<<endl;
        return 0;
    }
    ans =(((power(2,k)*(x%mod))%mod-power(2,k-1))+mod)%mod;
    ans=(ans+1)%mod;
    cout<<ans<<endl;
    return 0;
}