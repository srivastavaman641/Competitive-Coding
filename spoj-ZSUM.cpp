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
#define mod 10000007
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
	x=x%MOD;
	while(y)
	{
		if(y & 1)
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
	ll n,k;
	while(1)
	{
		cin>>n>>k;
		if(n==0 && k==0)
			break;
		ll ans=((power(n,n,mod)+(2*power(n-1,n-1,mod))%mod)%mod+(power(n,k,mod)+(2*power(n-1,k,mod))%mod)%mod)%mod;
		cout<<ans<<endl;
	}
	return 0;
}
