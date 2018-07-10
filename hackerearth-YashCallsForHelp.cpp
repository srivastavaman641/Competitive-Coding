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
ll a[1000005],b[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,d,mx=0,mn=INF;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
	}
	ll low=mn,high=mx,ans=mx+1;
	while(low<=high)
	{
		ll mid=(low+high)/2;
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=mid)
			{
				b[min(i+d+1,n+1)]+=mid;
				b[max(i-d,0ll)]-=mid;
			}
		}
		for(int i=1;i<=n;i++){
			b[i]+=b[i-1];
			if(a[i]+b[i]>=1){
				flag=0;
				break;
			}
		}
		// for(int i=1;i<=n;i++){
		// 	cout<<b[i]<<" ";
		if(flag==0)
		{
			low=mid+1;
			for(int i=0;i<=n+1;i++)
				b[i]=0;
		}
		else
		{
			ans=min(ans,mid);
			high=mid-1;
			for(int i=0;i<=n+1;i++)
				b[i]=0;
		}		
	}
	cout<<ans<<endl;


	return 0;
}
