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
ll ar[25];
ll power(ll x)
{
	ll ans=1;
	while(x)
	{	
		ans=(ans*10)%210;
		x--;
	}
	return ans;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;
   cin>>n;
   if(n<3)
   {
   		cout<<-1;
   		return 0;
   }
   if(n==3)
   {
   	cout<<210;
   	return 0;
   }
  	string s="";
  	s+="1";
   for(ll i=1;i<n;i++)
   {
   		s+="0";
   }
   for(int i=4;i<=9;i++)
   {
   		ll a=power(i-1);
   		
   		ar[i-3]=a;
   }
 
   ll x=(n-3)%6;
   if(x==0)
   	x=6;
   ll ans=210-ar[x];
   
   stringstream ss;
   ss<<ans;
   string str=ss.str();
   string s1=s.substr(0,n-str.length());
   s1+=str;
   cout<<s1;
   ent;
   return 0;
}
