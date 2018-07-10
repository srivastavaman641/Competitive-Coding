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
ll dp[100005][4],a[100005][4];
int x[]={0,1,1,1};
int y[]={1,1,-1,0};
int n;
ll recur(int i,int j)
{
	if(i==n && j==2)
		return a[i][j];
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans=INT_MAX;
	for(int k=0;k<4;k++){
		if(i+x[k]<=n && i+x[k]>0 && j+y[k]>0 && j+y[k]<=3)
		{
			ans=min(ans,a[i][j]+recur(i+x[k],j+y[k]));
		}
	}
	return dp[i][j]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt=1;
	while(1){
		cin>>n;
		if(n==0)
			break;
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
				cin>>a[i][j];
		}
		cout<<cnt<<". "<<recur(1,2)<<endl;
		cnt++;
	}
	return 0;
}
