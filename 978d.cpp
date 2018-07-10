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
ll a[100005];
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   		cin>>a[i];
   }
   if(n<=2)
   {
   		cout<<0<<endl;
   		return 0;
   }
   ll ans=INF;
   for(int i=-1;i<=1;i++)
   {
   		for(int j=-1;j<=1;j++)
   		{
   			ll d=a[1]+j-a[0]-i;
   			ll cnt=abs(i)+abs(j);
   			for(int k=2;k<n;k++)
   			{
   				ll an=a[0]+i+k*d;
   				if(abs(an-a[k])>1){
   					cnt=INF;
   					break;
   				}
   				else
   				{
   					cnt+=abs(an-a[k]);
   				}
   			}
   			ans=min(ans,cnt);
   		}
   }
   if(ans==INF)
   		ans=-1;
   cout<<ans<<endl;

   return 0;
}
	