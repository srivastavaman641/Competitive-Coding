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
#define mod 998244353
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
		if(y%2)
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
	ll n,m;
	cin>>n>>m;
	ll ans=0;
	ll fact[m+5];
	fact[0]=1;
	fact[1]=1;
	for(ll i=2;i<=m;i++)
	{
		fact[i]=(i*fact[i-1])%mod;
	}
	for(ll k=0;k<=m;k++)
	{
		ll x=(fact[m-k]*fact[k])%mod;
		ll z=power(2,m-k,mod)%mod;
		ll a=(power(x,mod-2,mod))%mod;
		if(a<0)a+=mod;
		ll b=fact[m];
		ll c=(power(z-1,n,mod))%mod;
		ll p=(b*a)%mod;
		ll y=(p*c)%mod;
		if(k%2==0)
			ans=(ans+y)%mod;
		else
			ans=(ans-y)%mod;

	}
	if(ans<0)
		ans=ans+mod;
	cout<<ans<<endl;
	return 0;
}
