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
bool dp[1005][1005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		memset(dp,0,sizeof dp);
   		string s;
   		cin>>s;
   		ll ans=0;
   		int n=s.length();
   		for(int i=0;i<n;i++){
   			dp[i][i]=1;
   			ans++;
   		}
   		for(int i=0;i<n-1;i++)
   		{
   			if(s[i]==s[i+1]){
   				dp[i][i+1]=1;
   				ans=ans+2*2;
   			}
   		}
   		for(int i=3;i<=n;i++)
   		{
   			for(int j=0;j<n-i+1;j++)
   			{
   				int l=i+j-1;
   				if(dp[j+1][l-1] && s[l]==s[j]){
   					dp[j][l]=1;
   					ans=ans+i*i;
   				}
   				else
   					dp[j][l]=0;
   			}
   		}
   		cout<<ans<<endl;
   }


   return 0;
}
