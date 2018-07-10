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
  
   int n;
   cin>>n;
   map<ll,ll> mp;
   int a=1,b=1;
   mp[a]=1;
   mp[b]=1;
   for(int i=3;i<=1000;i++)
   {
   	ll c=a+b;
   	mp[c]=1;
   	a=b;
   	b=c;
   }
   string s="";
   for(int i=1;i<=n;i++)
   {	
    if(mp[i])
    	s+="O";
    else
    	s+="o";
   }
   
   cout<<s<<endl;

   return 0;
}
