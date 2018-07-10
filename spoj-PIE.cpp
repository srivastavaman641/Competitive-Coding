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
double a[10005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   double pi=acos(-1);
   while(t--)
   {
   		ll n,k;
   		cin>>n>>k;
   		double mx;
   		for(int i=1;i<=n;i++){
   			cin>>a[i];
   			mx=max(mx,a[i]);
   			a[i]=pi*a[i]*a[i];
   		}
   		double low=0.0,high=mx,ans=0,mid=0;
   		while(high-low>0.00000001)
   		{
   			mid=(low+high)/2;
   			ll cnt=0;
   			double v=pi*mid*mid;
   			for(int i=1;i<=n;i++)
   			{
   				cnt+=(a[i]/v);
   			}
   			if(cnt>=k+1)
   			{
   				ans=max(ans,v);
   				low=mid;
   			}
   			else
   				high=mid;
   		}
   		printf("%.4lf\n",ans);

   }


   return 0;
}
