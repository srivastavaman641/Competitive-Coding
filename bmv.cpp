#include<bits/stdc++.h>
#define LL long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(i=0;i<n;i++)
#define fd(i,n) for(i=n-1;i>=0;i--)
#define p(a) printf("%d",a)
#define pl(a) printf("%lld",a)
#define ps(a) printf("%s",a)
#define pc(a) printf("%c",a)
#define ent printf("\n")
#define mod 1000000007
#define PI 3.14159265
#define gs getline(cin,s)
#define pb push_back
#define mp make_pair
#define INF 1e18

using namespace std;

LL ar[100005];
LL sm1[100005];
LL sm2[100005];
int main()
{
  LL n,m;
  cin>>n>>m;

  int i,j;

  ar[0]=0;
  ar[n+1]=m;
  ar[n+2]=m;
  for(i=1;i<=n;i++)
  {
      cin>>ar[i];
      if(i&1)
        sm1[i]=sm1[i-1]+ar[i]-ar[i-1];
      else
        sm1[i]=sm1[i-1];
  }
  if((n&1)==0)
    sm1[n+1]=sm1[n]+m-ar[n];
    else
        sm1[n+1]=sm1[n];
    sm2[n+1]=0;
    sm2[n+2]=0;
  for(i=n+1;i>=1;i--)
  {

          if((i&1))
            sm2[i]=sm2[i+1]+ar[i+1]-ar[i];
          else
            sm2[i]=sm2[i+1];

  }
  LL mx=sm1[n+1];
  for(i=1;i<=n+1;i++)
  {
      if(i&1)
      {
          mx=max(mx,sm1[i]-1+sm2[i]);
      }
      else
        mx=max(mx,sm1[i]+ar[i]-ar[i-1]-1+sm2[i]);
  }
  cout<<mx<<endl;
  return 0;
}