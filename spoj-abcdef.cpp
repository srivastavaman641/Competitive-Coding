#include<bits/stdc++.h>
#include <tr1/unordered_map>

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

using namespace std::tr1;
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   int a[n];
   vector<ll>v1;
   unordered_map<int,int> mp;
   for(int i=0;i<n;i++)
   		cin>>a[i];
   	sort(a,a+n);

   for(int i=0;i<n;i++)
   {
   	if(a[i]!=0){
   		for(int j=0;j<n;j++)
   		{
   			for(int k=0;k<n;k++)
   			{

   				v1.pb(a[i]*a[j]+a[k]);
   			}
   		}
   	}
   }

   for(int i=0;i<n;i++)
   {
   		for(int j=0;j<n;j++)
   		{
   			for(int k=0;k<n;k++)
   			{
   				mp[a[i]*(a[j]+a[k])]++;
   			}
   		}
   }
   ll ans=0;
   for(int i=0;i<v1.size();i++)
   {
   		ans+=mp[v1[i]];
   }

   cout<<ans<<endl;

   return 0;
}
