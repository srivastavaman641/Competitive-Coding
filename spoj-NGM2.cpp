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
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
using namespace std;
ll a[16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,k,c=0,ans=0;
	cin>>n>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	ans=n;
	for(ll i=1;i<(1<<k);i++)
	{
		ll lc=1,cn=0;
		for(ll j=0;j<k;j++)
		{
			if(i & (1<<j))
			{
				cn++;
				lc=lcm(a[j],lc);
			}
		}
		if(cn & 1){
			ans-=(n/lc);
		}
		else
		{
			ans+=(n/lc);
		}
	}
	cout<<ans<<endl;

	return 0;
}
