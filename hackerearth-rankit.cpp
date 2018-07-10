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
ll a[100005],b[100005];
map<ll,ll>m;
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
   		cin>>a[i];
   		b[i]=a[i];
   }
   sort(b,b+n);
   for(int i=0;i<n;i++)
   {
   		ll x = lower_bound(b,b+n,a[i]) - b;
   		m[a[i]]	= x+1;
   		a[i]=x+1;
   }
   int q;
   cin>>q;
   while(q--)
   {
   		ll x;
   		cin>>x;
   		cout<<m[x]<<endl;
   }

   return 0;
}
	