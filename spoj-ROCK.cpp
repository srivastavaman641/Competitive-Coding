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
int n;
string s;
ll dp[205][205];
ll a[205];
ll recur(int l,int h)
{
	if(l>h)
		return 0;
	if(l==h)
		return s[l]-'0';
	if(l==0)
	{
		if(a[h]>(h+1)/2)
			return h+1;
	}
	else if(a[h]-a[l-1]>(h-l+1)/2)
		return h-l+1;
	if(dp[l][h]!=-1)
		return dp[l][h];
	ll ans=0;
	for(int i=l+1;i<=h;i++)
		ans=max(ans,recur(l,i-1)+recur(i,h));
	return dp[l][h]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		memset(a,0,sizeof a);
		if(s[0]=='1')
			a[0]=1;
		else
			a[0]=0;
		for(int i=1;i<n;i++)
		{
			if(s[i]=='1')
				a[i]=1+a[i-1];
			else
				a[i]=a[i-1];
		}
		memset(dp,-1,sizeof dp);
		cout<<recur(0,n-1)<<endl;

	}


	return 0;
}
