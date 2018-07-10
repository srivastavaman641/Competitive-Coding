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
ll dp[1005][1005],a[1005];
ll recur(int l,int r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l>r)
		return 0;
	if(l==r)
		return a[l];
	ll ans=0;
	if(a[l+1]>=a[r])
	{
		ans=a[l]-a[l+1]+recur(l+2,r);
	}
	else
	{
		ans=a[l]-a[r]+recur(l+1,r-1);
	}
	if(a[l]>=a[r-1])
	{
		ans=max(a[r]-a[l]+recur(l+1,r-1),ans);
	}
	else
	{
		ans=max(a[r]-a[r-1]+recur(l,r-2),ans);
	}
	return dp[l][r]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int g=0;
   while(1)
   {
   		g++;
   		int n;
   		cin>>n;
   		if(n==0)
   			break;
   		memset(dp,-1,sizeof dp);
   		memset(a,0,sizeof a);
   		for(int i=1;i<=n;i++)
   		{
   			cin>>a[i];
   		}
   		ll x=recur(1,n);
   		/*for(int i=1;i<=n;i++)
   		{
   			for(int j=1;j<=n;j++)
   			{
   				cout<<dp[i][j]<<" ";
   			}
   			cout<<endl;
   		}*/
   		
   		cout<<"In game "<<g<<", the greedy strategy might lose by as many as "<<x<<" points."<<endl;
   }


   return 0;
}
