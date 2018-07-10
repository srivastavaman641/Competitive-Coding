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
ll a[10005],lm[10005],lx[10005],rm[10005],rx[10005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		int n;
   		cin>>n;
   		for(int i=0;i<n;i++)
   		{
   			cin>>a[i];
   		}
   		lm[0]=lx[0]=a[0];
   		for(int i=1;i<n;i++)
   		{
   			lx[i]=max(lx[i-1]+a[i],a[i]);
   			lm[i]=min(lm[i-1]+a[i],a[i]);
   		}
   		rx[n-1]=a[n-1];
   		rm[n-1]=a[n-1];
   		for(int i=n-2;i>=0;i--)
   		{
   			rx[i]=max(rx[i+1]+a[i],a[i]);
   			rm[i]=min(rm[i+1]+a[i],a[i]);
   		}
   		ll ans=0;
   		for(int i=0;i<n-1;i++)
   		{
   			ans=max(ans,abs(lx[i]-rm[i+1]));
   			ans=max(ans,abs(rx[i+1]-lm[i]));
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
