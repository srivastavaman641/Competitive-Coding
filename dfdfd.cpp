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
LL tz[200005];

int main()
{
     memset(tz,0,sizeof tz);
     LL n;
     cin>>n;
     LL i,j;
     for(i=1;i<=n;i++)
     {
         cin>>ar[i];
       //  v.pb(mp(ar[i],i));
     }
    // sort(v.begin(),v.end());
     //int cnt=1;


     LL st,fi;
     cin>>st>>fi;
LL x=(st);
LL y=(fi);

     for(i=1;i<=n;i++)
     {


         tz[x]+=ar[i];
         tz[y]-=ar[i];
         if(y<x)
            tz[1]+=ar[i];
       x--;
       y--;
       if(x<1)
        x=n;
       if(y<1)
        y=n;

     }
     LL mx=0;
     LL ans=0;
     for(i=1;i<=n;i++)
     {
         tz[i]=tz[i]+tz[i-1];
         //cout<<tz[i]<<" ";
     }
     //ent;
     for(i=1;i<=n;i++)
     {
         if((tz[i])>mx)
        {
            mx=tz[i];
            ans=i;
        }
     }




     cout<<ans<<endl;

     return 0;
}