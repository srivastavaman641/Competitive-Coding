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
ll dp[55];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   dp[1]=1;
   dp[2]=3;
   for(int i=3;i<=50;i++)
   {
   		for(int j=i-1;j>0;j--)
   			dp[i]+=dp[j];
   		dp[i]+=(ll)pow(2,i-1);
   }
   while(t--)
   {
   		int n;
   		cin>>n;
   		cout<<(ll)pow(2,n-1)<<" "<<dp[n]<<endl;
   }

   return 0;
}
