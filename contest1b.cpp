#include<bits/stdc++.h>

using namespace std;
#define ll long long int
ll a[100005],b[100005];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
      ll x,y;
      cin>>x>>y;
      a[i]=x;
      b[i]=y;
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
      ll temp1=a[i];
      ll temp2=b[i];
      ll flag=0;
      
      for(int j=i+1;j<n;j++)
      {
          if(temp1>=temp2)
          {
            temp1+=a[j];
            temp2+=b[j];
            flag=1;
          }
          else
          {
            flag=0;
            break;
          }
      }
      if(flag==1){
      for(int j=0;j<i;j++)
      {
          if(temp1>=temp2)
          {
            temp1+=a[j];
            temp2+=b[j];
          }
          else
          {
            flag=0;
            break;
          }

      }
    }
     if(flag==1)
     {
      ans=i;
      break;
     }
    }
    cout<<ans<<endl;
    return 0;
}