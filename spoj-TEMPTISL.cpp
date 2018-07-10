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
int n,k,st,en;
ll dp[55][55];
ll recur(int s,int cnt)
{
	if(cnt==0)
	{
		if(s==en)
			return 1;
		else
			return 0;
	}
	if(dp[s][cnt]!=-1)
		return dp[s][cnt];
	ll ans=0;
	int y=s-1,x=s+1;
	if(s==n)
		x=1;
	if(s==1)
		y=n;
	ans=recur(x,cnt-1)+recur(y,cnt-1);
	return dp[s][cnt]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1)
	{
		cin>>n>>k;
		if(n==-1 && k==-1)
			break;
		cin>>st>>en;
		memset(dp,-1,sizeof dp);
		cout<<recur(st,k)<<endl;
	}


	return 0;
}
