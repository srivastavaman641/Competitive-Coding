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
//#define mp make_pair
#define INF 1e18
#define pii pair<int,int>

using namespace std;
ll a[100005],b[100005];
map<int,int>mp;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n,m,ans=0;
   cin>>n>>m;
   for(int i=0;i<n;i++)
   {
   		cin>>a[i];
   }
   for(int i=0;i<m;i++)
   {
   		cin>>b[i];
   }
   mp[a[0]]++;
   for(int i=1;i<n;i++)
   {
   		a[i]+=a[i-1];
   		mp[a[i]]++;
   }
   if(mp[b[0]])
   		ans++;
   for(int i=1;i<m;i++)
   {
   		b[i]+=b[i-1];
   		if(mp[b[i]])
   		{
   			ans++;
   		}
   }
   cout<<ans<<endl;

   return 0;
}
