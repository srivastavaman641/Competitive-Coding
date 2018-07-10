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
int a[105],b[105],c[105],d[105],e[105],f[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i]>>d[i]>>e[i]>>f[i];
	}
	int low=0,high=m,ans=0;
	while(low<=high)
	{
		int mid=(low+high)/2;
		int p=0;
		for(int i=1;i<=n;i++)
		{
			int req=mid*a[i]-b[i];
			double x=(req*1.0)/(1.0*c[i]);
			int lim=ceil(x);
			int mn=INT_MAX;
			for(int j=0;j<=lim;j++)
			{
				int sm=j*c[i];
				int lar=0;
				if(req>sm)
				{
					double y=(req-sm)*1.0/(1.0*e[i]);
					lar=ceil(y);
				}
				mn=min(mn,sm*d[i]+lar*f[i]);
			}
			p+=mn;
		}
		if(p<=m)
		{
			ans=max(ans,mid);
			low=mid+1;
		}
		else
			high=mid-1;
	}
	cout<<ans<<endl;


	return 0;
}
