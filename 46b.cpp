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
ll b[100005],a[100005],ans1[100005],ans2[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	b[n+1]=m;
	for(int i=1;i<=n+1;i++){
		a[i]=b[i]-b[i-1];
		if(i%2==1)
		{
			ans1[i]=a[i]+ans1[i-1];
			ans2[i]=ans2[i-1];
		}
		else
		{
			ans1[i]=ans1[i-1];
			ans2[i]=a[i]+ans2[i-1];
		}
	}
	ll mx=0;
	mx=max(ans1[n+1],mx);
	// cout<<mx<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1)
			mx=max(mx,ans1[i]+ans2[n+1]-ans2[i]-1);
		else
			mx=max(mx,ans1[i]+ans2[n+1]-ans2[i]+b[i+1]-b[i]-1);
	}
	cout<<mx<<endl;




	return 0;
}
