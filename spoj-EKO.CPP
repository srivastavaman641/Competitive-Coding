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
ll a[1000005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,k,low=0,high=0,ans=0,mx=0;
   cin>>n>>k;
   for (int i = 1; i <= n; ++i)
   {
   		cin>>a[i];
   		mx=max(mx,a[i]);
   }
   //sort(a,a+n+1);
   //reverse(a,a+n+1);
   high=mx;
   while(low<=high)
   {
   		ll mid=(low+high)/2;
   		ll cnt=0;
   		for(int i=1;i<=n;i++)
   		{
   			if(mid>=a[i])continue;
   			cnt+=(a[i]-mid);
   		}
   		if(cnt>=k){
   			ans=max(ans,mid);
   			low=mid+1;
   		}
   		else
   			high=mid-1;
   }
   cout<<ans<<endl;	


   return 0;
}
