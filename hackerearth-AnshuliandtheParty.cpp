#include<bits/stdc++.h>
#define ll unsigned long long int
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
ll power(ll x,ll y,ll MOD)
{
	ll ans=1;
	while(y)
	{
		if(y&1)
			ans=(ans*x)%MOD;
		x=(x*x)%MOD;
		y/=2;
	}
	return ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		string s,s1;
   		cin>>s>>s1;
   		ll n=s.length(),m=s1.length();
   		ll x=0,y=0;
   		for(ll i=0;i<n;i++)
   		{
   			x=(s[i]-'0'+x*10)%mod;
   		}
   		for(ll i=0;i<m;i++)
   		{
   			y=(s1[i]-'0'+y*10)%mod;
   		}
   		cout<<power(x,y,mod)<<endl;
   }


   return 0;
}
