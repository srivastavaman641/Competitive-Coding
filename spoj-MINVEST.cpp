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
ll dp[100005],a[1005],w[1005];
ll n;
ll recur(int m)
{
	if(m<0)
		return INT_MIN;
	if(m==0)
		return 0;
	if(dp[m]!=-1)
		return dp[m];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,a[i]+recur(m-w[i]));
	}
	return dp[m]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		ll m,d;
   		cin>>m>>d>>n;
   		int rem=m%1000;
   		m/=1000;
   		for(int i=1;i<=n;i++){
   			cin>>w[i]>>a[i];
   			w[i]/=1000;
   		}
   		memset(dp,-1,sizeof dp);
   		ll ans=0;
   		ll k=m;
   		for(int i=1;i<=d;i++){
   			ans=max(ans,recur(m));
   			m=m+(ans+rem)/1000;
   			rem=(ans+rem)%1000;
   		}
   		cout<<m*1000+rem<<endl;
   }


   return 0;
}
