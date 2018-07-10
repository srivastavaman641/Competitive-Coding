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
ll dp[1005][1005];
int n;
ll a[1005];
ll recur(int x,int k)
{
	if(dp[x][k]!=-1)
		return dp[x][k];
	if(x>n || k==0)
		return 0;
	ll ans=0;
	if(a[x]>k)
		ans=recur(x+1,k);
	else
		ans=max(a[x]+recur(x+2,k-a[x]),recur(x+1,k));
	return dp[x][k]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	int cnt=0;
	while(t--)
	{
		cnt++;
		int k;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		memset(dp,-1,sizeof dp);
		cout<<"Scenario #"<<cnt<<": "<<recur(1,k)<<endl;
	}


	return 0;
}
