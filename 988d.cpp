#include<bits/stdc++.h>
#define ll long long 
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	ll a[n+1];
	map<ll,bool>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]=1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		ll x=a[i];
		ll y=1;
		for(int j=1;j<=31;j++){
			if(m[x+y] && m[x+2*y])
			{
				cout<<3<<"\n";
				cout<<x<<" ";
				cout<<(x+y)<<" ";
				cout<<(x+2*y);
				return 0;
			}
			y=y*2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll x=a[i];
		ll y=1;
		int cnt=0;
		for(int j=1;j<=31;j++){
			if(m[x+y])
			{
				cout<<2<<"\n";
				cout<<x<<" ";
				cout<<x+y;
				return 0;
			}
			y=y*2;
		}
	}
	cout<<1<<"\n";
	cout<<a[1];

	return 0;
}
