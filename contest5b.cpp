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
ll a[100005];
int binarySearch(ll l, ll r, ll x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
    if (a[m] == x) 
        return 1;   
    if (a[m] < x) 
        l = m + 1; 
 
    else
         r = m - 1; 
  }
 
  return 0; 
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll n,k;
   cin>>n>>k;
   for(ll i=0;i<n;i++)
   {
   	cin>>a[i];
   }
   sort(a,a+n);
   ll ans=0;
   for(ll i=0;i<n;i++)
   {
   	if(binarySearch(i+1,n-1,a[i]+k))
   		ans++;
   }
   cout<<ans<<endl;
   return 0;
}