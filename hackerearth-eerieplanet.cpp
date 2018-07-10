#include<bits/stdc++.h>
#define ll long long int
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
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
#define ss second
#define ff first

using namespace std;

vector<pair<ll,pii> >v;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll h,c,q;
   cin>>h>>c>>q;
   for(int i=0;i<c;i++){
   		ll a,s,e;
   		cin>>a>>s>>e;
   		v.pb(mp(a,mp(s,e)));
   }
   sort(v.rbegin(),v.rend());
   while(q--)
   {
   		int H,t;
   		cin>>H>>t;
   		ll flag=1;
   		for(int i=0;i<v.size();i++)
   		{
   			ll val=v[i].ff;
   			ll p=v[i].ss.ff;
   			ll r=v[i].ss.ss;
   			if(val>=H && p<=t && r>=t){
   				flag=0;
   				break;
   			}
   			if(val<H)
   				break;
   		}
   		if(flag)
   			cout<<"YES"<<endl;
   		else
   			cout<<"NO"<<endl;
   }


   return 0;
}
