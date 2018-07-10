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
map<ll,ll>m;
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
vector<ll> divis(ll n)
{
	vector<ll> ans;
	for(ll i=2;i*i<=n;i++)
	{

		if(n%i==0)
		{
			ll x=n/i;
			ans.pb(i);
			if(x!=i)
				ans.pb(x);
		}
	}
	return ans;
}
ll recur(ll n)
{
	if(n==1 || n==2)
		return 1;
	if(m[n])
		return m[n];

	ll x=n-1;
	ll ans=1;
	vector<ll> v=divis(x);
	for(int i=0;i<v.size();i++)
	{
		ans+=(power(recur(v[i]),x/v[i],mod));
		ans%=mod;
	}
	return m[n]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;
   cin>>n;
   cout<<recur(n)<<endl;


   return 0;
}
