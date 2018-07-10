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
int dp[505][505];
int a[505];
int recur(int i,int j)
{
	//cout<<i<<" "<<j<<endl;
	if(i>j)
		return 0;
	if(i==j)
		return 1;
	if(dp[i][j]!=-1)
		return dp[i][j];
	int ans=INT_MAX;
	if(a[i]==a[j])
		ans=recur(i+1,j-1);
	else{
		for(int k=i;k<j;k++){
			ans=min(ans,recur(i,k)+recur(k+1,j));
		}
	}
	return dp[i][j]=ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   memset(dp,-1,sizeof dp);
   for(int i=1;i<=n;i++)
   {
   		cin>>a[i];
   }
   cout<<recur(1,n)<<endl;
   return 0;
}