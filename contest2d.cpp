#include<bits/stdc++.h>

using namespace std;
#define ll long long int
ll a[100005];
int main()
{
	ll n,q;
  cin>>n>>q;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  while(q--)
  {
    ll mx=0,mn=INT_MAX;
     int d;
     cin>>d;
     for(int i=0;i<d;i++)
     {
       mx=max(mx,a[i]);
     }
     for(int i=d;i<n;i++)
     {
      mn=min(mn,mx);
      if(mx!=a[i-d])
      {
         mx=max(mx,a[i]);
      }
      else
      {
        mx=0;
        for(int j=i-d+1;j<=i;j++)
        {
          
          mx=max(mx,a[j]);
        }
      }
      
     }
     mn=min(mn,mx);
    cout<<mn<<endl; 
}
return 0;
}