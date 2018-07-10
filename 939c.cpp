#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define w(t) while(t--)
#define f(i,n) for(int i=0;i<n;i++)
#define fd(i,n) for(int i=n-1;i>=0;i--)
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
#define pii pair<int,int>

using namespace std;
ll a[100005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,s,f;
   cin>>n;
   for(ll i=1;i<=n;i++)
   		cin>>a[i];

   cin>>s>>f;
   for(ll i=2;i<=n;i++)
   		a[i]+=a[i-1];

   ll l=1,j=(f-s),mx=0,ans=0,idx=n+1;
   a[0]=0;
   for(ll i=1;i<=n;i++)
   {
   		l=i;
   		j=l+(f-s-1);
   		if(j>n)
   			j-=n;
   		
   		if(j>l)
   		{
   			ans=a[j]-a[l-1];
   			if(ans>=mx)
   			{
   				
   				ll x=s-(i-1);
   				if(x<=0)
   					x+=n;
   				 if(ans>mx)
   				 {
   					idx=x;
   					mx=ans;
   				}
   				if(ans==mx && x<(idx))
   					idx=x;
   			   
   			}
   		}
   		else
   		{
   			ans=a[n]-a[l-1];
   			ans+=a[j];
   			if(ans>=mx)
   			{
   				
   			    ll x=s-(i-1);
   				if(x<=0)
   					x+=n;
   				 if(ans>mx)
   				 {
   					idx=x;
   					mx=ans;
   				}
   				if(ans==mx && x<(idx))
   					idx=x;
   				
   			}

   		}
   }

  

   cout<<idx;

   return 0;
}
