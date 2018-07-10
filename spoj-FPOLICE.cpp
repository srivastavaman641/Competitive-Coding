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
ll a[105][105],b[105][105];
ll dp[105][255];
int n,t;
ll recur(int pos,int l)
{
	//cout<<pos<<" "<<l<<endl;
	if(l<0)
		return INT_MAX;
	if(pos==1)
		return 0;
	if(dp[pos][l]!=-1)
		return dp[pos][l];
	ll ans=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		if(i==pos)continue;
		ans=min(ans,b[pos][i]+recur(i,l-a[pos][i]));
	}
	return dp[pos][l]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>q;
	while(q--)
	{
		cin>>n>>t;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cin>>b[i][j];
		}
		memset(dp,-1,sizeof dp);
		ll ans=recur(n,t);
		ll time=0;
		if(ans==INT_MAX)
		{
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<=t;i++)
		{
			if(recur(n,i)==ans)
			{
				time=i;
				break;
			}
		}
		cout<<ans<<" "<<time<<endl;
	}


	return 0;
}
