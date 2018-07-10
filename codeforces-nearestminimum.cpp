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
vector<pair<ll,ll> >v;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n;
   cin>>n;
   for(ll i=0;i<n;i++)
   {
   	ll x;
   	cin>>x;
   	v.pb(mp(x,i));
   }
   sort(v.begin(),v.end());
   ll mn=v[0].first;
   ll i=1,ans=INT_MAX;
   while(v[i].first==mn)
   {
   	ans=min(ans,v[i].second-v[i-1].second);
   	i++;
   }
   cout<<ans<<endl;
   return 0;
}
