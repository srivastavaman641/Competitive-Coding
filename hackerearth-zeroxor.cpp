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
ll x[2000005],y[2000005],a[45];
ll calculatexor(ll a[],ll arr[],ll sz,ll start)
{
	for(int i=0;i<(1<<sz);i++)
	{
		ll xr=0;
		for(int j=0;j<sz;j++)
		{
			if(i & (1<<j))
			{
				xr^=a[j+start];
			}
		}
		arr[i]=xr;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	calculatexor(a,x,n/2,0); 
	calculatexor(a,y,n-n/2,n/2);
	ll szx = 1<<(n/2);
	ll szy = 1<<(n-n/2);
	sort(y,y+szy);
	ll ans=0;
	for(int i=0;i<szx;i++)
	{
		ll val = x[i];
		ll an = upper_bound(y,y+szy,val) - lower_bound(y,y+szy,val);
		ans+=an;
	}
	cout<<ans-1<<endl;
	return 0;
}
