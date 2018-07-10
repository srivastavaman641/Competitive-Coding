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
vector<int> dp[100005],a[100005];
int n,m;
int recur(int x,int prev)
{
	if(x>n)
		return 0;
	if(dp[x][prev]!=0)
		return dp[x][prev];
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(i!=prev){
			ans=max(ans,a[x][i]+recur(x+1,i));
		}
	}
	return dp[x][prev]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		cin>>n>>m;
   		for(int i=0;i<=n;i++){
   			dp[i].resize(m+2);
   			a[i].resize(m+2);
   			dp[i].clear();
   		}
   		for(int i=1;i<=n;i++)
   			for(int j=1;j<=m;j++)
   				cin>>a[i][j];
   		cout<<recur(1,0)<<endl;
   }
   return 0;
}