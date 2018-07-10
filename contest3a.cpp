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
/*inline ll recur(ll x)
{
	if(x<10)
		return x;
	return x%10 +recur(x/10);
	}*/
inline ll fn(ll x)

{
	if(x<10)

		return x;
	ll a=x,s=0;
	while(a!=0)
	{
		s+=a%10;
		a=a/10;
	}
      
	return fn(s);
}
/*ll digitsum(ll x)
{
	ll s=0;
	while(x!=0)
	{
        s+=x%10;
        x=x/10;
	}
	return s;
}*/
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   ll k;
   cin>>s;
   cin>>k;
   string p="";
   ll sum=0;
   for(ll i=0;i<s.length();i++)
   {
   	  sum+=s[i]-'0';
   }
   sum=k*sum;

   ll ans=fn(sum);
   	cout<<ans<<endl;
   return 0;
}
