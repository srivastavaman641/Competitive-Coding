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
ll a[100005],b[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		a[0]=b[0]=0;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
			a[i]=a[i]+a[i-1];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>b[i];
			b[i]=b[i]+b[i-1];
		}
		if(n==1)
		{
			cout<<(m*(a[m]%mod))%mod<<endl;
		}
		else if(n==2)
		{
			cout<<(m*(b[m]%mod))%mod<<endl;
		}
		else if(n==3)
		{
			cout<<(m*((a[m]+b[m])%mod))%mod<<endl;
		}
		else{
			n-=3;
			ll x1=1,y1=2;
			ll x2=2,y2=3;
			if(n==1){
				y1=x1;
				y2=x2;
			}
			for(int i=3;i<=n;i++)
			{
				ll z=y1;
				y1=(x1+y1)%mod;
				x1=z;

				z=y2;
				y2=(x2+y2)%mod;
				x2=z;
			}
   			//cout<<y1<<" "<<y2<<endl;
			ll ans=((((y1*m)%mod)*(a[m]%mod))%mod+(((y2*m)%mod)*(b[m]%mod))%mod)%mod;
			cout<<ans<<endl;
		}
	}


	return 0;
}
