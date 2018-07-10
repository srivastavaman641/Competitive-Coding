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

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,m,c1,c2;
   cin>>n>>m>>c1>>c2;
   if(n%m==0)
   {
   		cout<<0<<endl;
   		return 0;
   }
   else
   {
   		ll x=n%m;
   		ll y=n/m;
   		ll ans=min(x*c2,((m*(y+1)-n)*c1));
   		cout<<ans<<endl;
   }


   return 0;
}
