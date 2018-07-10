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
ll a[3005],val[3005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   		cin>>a[i];
   for(int i=1;i<=n;i++)
   		cin>>val[i];
   	ll ans=INT_MAX;
   for(int i=2;i<n;i++)
   {
   		ll mn1=INT_MAX,mn2=INT_MAX;
   		ll k=a[i];
   		for(int j=1;j<i;j++)
   		{
   			if(a[j]<a[i]){
   				mn1=min(mn1,val[j]);
   			}
   		}
   		for(int j=i+1;j<=n;j++)
   		{
   			if(a[j]>a[i])
   				mn2=min(mn2,val[j]);
   		}
   		ans=min(ans,val[i]+mn1+mn2);
   }
   if(ans==INT_MAX)
   		ans=-1;
   cout<<ans<<endl;


   return 0;
}
