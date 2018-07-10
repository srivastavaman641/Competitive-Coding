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
ll a[2505],b[2505],c[2505],d[2505];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,ans=0;
	cin>>n;
	vector<ll>v;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i]>>d[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			v.pb(c[i]+d[j]);
		}
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int x=lower_bound(v.begin(),v.end(),-(a[i]+b[j]))-v.begin();
			int y=upper_bound(v.begin(),v.end(),-(a[i]+b[j]))-v.begin();
			ans+=(y-x);		
		}
	}
	cout<<ans<<endl;
	return 0;
}
