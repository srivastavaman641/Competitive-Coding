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
ll gcd(ll x,ll y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y)
{
	return (x*y)/gcd(x,y);
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int t;
   cin>>t;
   while(t--)
   {
   		ll n,a,b,c,la,lb,lc,lab,lbc,lac,labc;
   		cin>>n>>a>>b>>c;
   		la=n/a;
   		lb=n/b;
   		lc=n/c;
   		lab=n/lcm(a,b);
   		lbc=n/lcm(b,c);
   		lac=n/lcm(a,c);
   		labc=n/lcm(lcm(a,b),c);
   		cout<<la+lb+lc-lab-lbc-lac+labc<<endl;
   }


   return 0;
}
