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
int a[6];
int dp[100005];
int c[7];
int n,k;
ll recur(int x)
{
	if(x<0)
		return 0;
	if(x==0)
	{
		for(int i=k;i>=1;i--){
			if(c[i]<c[i+1])
				return 0;
		}
		return 1;
	}
	if(dp[x]!=-1)
		return dp[x];
	int ans=0;
	for(int i=1;i<=k;i++)
	{
		c[i]++;
		ans=ans|recur(x-a[i]);
		c[i]--;
		if(ans==1)
			break;
	}
	return dp[x]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=k;i++)
		cin>>a[i];
	memset(dp,-1,sizeof dp);
	int ans=recur(n);
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}
