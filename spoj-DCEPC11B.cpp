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
	int t;
	cin>>t;
	while(t--)
	{
		ll n,p;
		cin>>n>>p;
		ll ans=p-1;
		if(n<p){
			for(ll i=n+1;i<=p-1;i++)
			{
				ans=(ans*power(i,p-2,p))%p;
			}
		}
		else
		{
			for(int i=n;i>=p;i--)
				ans=(ans*i)%p;
		}
		if(ans<0)ans+=p;
		cout<<ans<<endl;
	}


	return 0;
}
