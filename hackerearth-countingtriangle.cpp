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
   map< pair< ll,pair< ll,ll> >,ll>mp1;
    map< pair< ll,pair< ll,ll> >,ll>:: iterator it;
   for(int i=0;i<n;i++)
   {
   		ll a[3];
   		cin>>a[0]>>a[1]>>a[2];
   		sort(a,a+3);
   		pair<ll,pair<ll,ll> >p=mp(a[0],mp(a[1],a[2]));
   		mp1[p]++;
   }
   ll cnt=0;
   for(it=mp1.begin();it!=mp1.end();it++)
   {
   		if(it->second==1)
   			cnt++;
   }
   cout<<cnt<<endl;
   return 0;
}
