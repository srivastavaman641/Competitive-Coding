#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll ar[200000];
int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>ar[i];
    ll mini=1e18;
    for(ll i=0;i<n;i++)
        mini=min(ar[i],mini);
    for(ll i=0;i<n;i++)
    {
        ar[i]-=mini;
    }
    ll idx=mini%n;
    ll cnt=0;
    while(ar[idx]!=0)
    {
        ar[idx]-=cnt++;
        if(ar[idx]<=0)
            break;
        idx=(idx+1)%n;
    }
    cout<<idx+1;
    return 0;
}